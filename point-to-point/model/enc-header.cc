#include <stdint.h>
#include <iostream>
#include "enc-header.h"
#include "ns3/buffer.h"
#include "ns3/address-utils.h"
#include "ns3/log.h"

NS_LOG_COMPONENT_DEFINE("encHeader");

namespace ns3 {

	NS_OBJECT_ENSURE_REGISTERED(encHeader);

	encHeader::encHeader()
		:  sport(0), dport(0), isOwn(0)
	{}

	encHeader::~encHeader()
	{}

	void encHeader::SetSport(uint32_t _sport){
		sport = _sport;
	}
	void encHeader::SetDport(uint32_t _dport){
		dport = _dport;
	}

	void encHeader::SetIsOwn(uint8_t _isOwn) {
        isOwn = _isOwn;
    }

	void encHeader::SetMyIntHeader(const MyIntHeader &_ih){
		ih = _ih;
	}

	uint16_t encHeader::GetSport() const{
		return sport;
	}
	uint16_t encHeader::GetDport() const{
		return dport;
	}

	uint8_t encHeader::GetIsOwn() const{
        return isOwn;
    }

	TypeId
		encHeader::GetTypeId(void)
	{
		static TypeId tid = TypeId("ns3::encHeader")
			.SetParent<Header>()
			.AddConstructor<encHeader>()
			;
		return tid;
	}
	TypeId
		encHeader::GetInstanceTypeId(void) const
	{
		return GetTypeId();
	}
	void encHeader::Print(std::ostream &os) const
	{
		os << "enc:" << "sport=" << sport << ",dport" << dport;
	}
	uint32_t encHeader::GetSerializedSize(void)  const
	{
		return GetBaseSize() + MyIntHeader::GetStaticSize();
	}
	uint32_t encHeader::GetBaseSize() {
		encHeader tmp;
		return sizeof(tmp.sport) + sizeof(tmp.dport) + sizeof(tmp.isOwn);
	}
	void encHeader::Serialize(Buffer::Iterator start)  const
	{
		Buffer::Iterator i = start;
		i.WriteU16(sport);
		i.WriteU16(dport);
		i.WriteU8(isOwn);

		// write MyIntHeader
		ih.Serialize(i);
	}

	uint32_t encHeader::Deserialize(Buffer::Iterator start)
	{
		Buffer::Iterator i = start;
		sport = i.ReadU16();
		dport = i.ReadU16();
		isOwn = i.ReadU8();

		// read MyIntHeader
		ih.Deserialize(i);
		return GetSerializedSize();
	}
}; // namespace ns3
