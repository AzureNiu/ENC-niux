#ifndef INT_HEADER_NIUX_H
#define INT_HEADER_NIUX_H

#include "ns3/buffer.h"
#include <stdint.h>
#include <cstdio>

namespace ns3 {

class headerInfo {
public:
	union {
		struct {
			uint32_t totalLength: 8,	// total length of this header in packet
							 nodeNum: 8,	// nodes count for routing
							 depthNum: 8,	// nodes count for depth info
							 ratioNum: 8;	// nodes count for ratio info
		};
		uint32_t buf;
	};

	headerInfo() {
		totalLength = 40;
		nodeNum = 0;
		depthNum = 0;
		ratioNum = 0;
	}
};


class depthInfo {
public:
	union {
		struct {
			uint32_t routeID: 8,
					     depth: 16,
							 maxRate: 8;
		};
		uint32_t buf;
	};
	void Set(uint8_t _routeID, uint16_t _depth, uint8_t _maxRate) {
		routeID = _routeID;
		depth = _depth;
		maxRate = _maxRate;
	}
};

class ratioInfo {
public:
	union {
		struct {
			uint32_t routeID: 8,
							 ratio: 16,
							 maxRate: 8;
		};
		uint32_t buf;
	};
	void Set(uint8_t _routeID, uint16_t _ratio, uint8_t _maxRate) {
		routeID = _routeID;
		ratio = _ratio;
		maxRate = _maxRate;
	}
};

class MyIntHeader {
public:
	static const uint32_t maxNum = 4;

	// headerInfo: 4 Bytes
	headerInfo hinfo;
	// routeInfo: 4 Bytes
	uint8_t routeInfo[maxNum];
	// depthInfo: Max 4*4 = 16 Bytes
	depthInfo dinfo[maxNum];
	// ratioInfo: Max 4*4 = 16 Bytes
	ratioInfo rinfo[maxNum];

	static const uint32_t qlenUnit = 80;

	MyIntHeader();
	void PushRoute(uint8_t rID);
	int PushDepth(uint8_t _routeID, uint32_t _depth, uint8_t _maxRate);
	int PushRatio(uint8_t _routeID, uint16_t _ratio, uint8_t _maxRate);
	void Serialize (Buffer::Iterator start) const;
	uint32_t Deserialize (Buffer::Iterator start);
};

}

#endif /* INT_HEADER_H */
