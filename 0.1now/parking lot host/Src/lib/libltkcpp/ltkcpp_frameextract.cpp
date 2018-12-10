
/*
 ***************************************************************************
 *  Copyright 2007,2008 Impinj, Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ***************************************************************************
 */


#include <assert.h>
#include <stdio.h>

#include "ltkcpp_platform.h"
#include "ltkcpp_base.h"
#include "ltkcpp_frame.h"


namespace LLRP
{

CFrameExtract::CFrameExtract (void)
{
	memset(this, 0, sizeof *this);
}

CFrameExtract::CFrameExtract (
  const unsigned char *         pBuffer,
  unsigned int                  nBuffer)
{
	memset(this, 0, sizeof *this);

	if(19u > nBuffer)    //参照无锡所LLRP的通信协议，帧头一共占用了19个字节。
	{
		m_MessageLength = 19u;  //在这里m_MessageLength保存的是这个消息的消息头长度
		m_nBytesNeeded = m_MessageLength - nBuffer;
		m_eStatus = NEED_MORE;     //设置状态为 NEED_MORE
	}
	else
	{	
		m_ProtocolVersion =  pBuffer[8];   //对应无锡所的LLRP中的Version[7:0]

		m_MessageType = pBuffer[9];
		m_MessageType <<= 8u;
		m_MessageType |= pBuffer[10];    //message Type 占用两个字节

		m_MessageLength = pBuffer[11];   //m_MessageLength一共占用32bit即4个字节。
		m_MessageLength <<= 8u;
		m_MessageLength |= pBuffer[12];
		m_MessageLength <<= 8u;
		m_MessageLength |= pBuffer[13];
		m_MessageLength <<= 8u;
		m_MessageLength |= pBuffer[14];

		/*
		 * Should we be picky about reserved bits?
		 */
		m_MessageID = pBuffer[15];
		m_MessageID <<= 8u;
		m_MessageID |= pBuffer[16];
		m_MessageID <<= 8u;
		m_MessageID |= pBuffer[17];
		m_MessageID <<= 8u;
		m_MessageID |= pBuffer[18];

		if(19u > m_MessageLength + 19u)   //m_MessageLength不包含帧头的长度的，所以要加上19。一帧数据中，只要帧头完整，就可以。
		{
			m_nBytesNeeded = 0;
			m_eStatus = FRAME_ERROR;
		}
		else if(nBuffer >= m_MessageLength + 19u)    //这里的nBuffer已经大于19了，如果，nBuffer再大于消息的长度，那么，说明可以去到一帧完整的数据
		{
			m_nBytesNeeded = 0;
			m_eStatus = READY;
		}
		else    //消息长度正常，但是缓冲区的长度不够，所以会设置 NEED_MORE，并且用m_nBytesNeeded来返回还需要的总长度
		{
			m_nBytesNeeded = m_MessageLength + 19 - nBuffer;
			m_eStatus = NEED_MORE;
		}
	}
}


}; /* namespace LLRP */

