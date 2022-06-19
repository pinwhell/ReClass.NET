#pragma once

#include <cstdint>
#include <stdio.h>
#include "PackDefs.h"

template <typename PacketType, uint16_t packetId>
PACK(struct Packet {
	uint16_t mPacketId = packetId;
	PacketType mPacketContent;

	void* getEntry()
	{
		return this;
	}

	size_t getSize()
	{
		return sizeof(PacketType) + sizeof(uint16_t);
	}

	PacketType* getPayload()
	{
		return &mPacketContent;
	}

	void Print()
	{
		for(int i = 0; i < getSize(); i++)
			printf("%02X ", ((uint8_t*)this)[i]);

		printf("\n");
	}
});