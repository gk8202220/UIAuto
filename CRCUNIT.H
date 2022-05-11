#ifndef CRCUNIT_H
#define CRCUNIT_H


class crcUnit
{
public:
    crcUnit();
    unsigned long crc16WithData(const  char * tbyte,unsigned int len);
    unsigned long crc16ByCrc16( unsigned long crc16,const char * tbyte,int len);

};

#endif // CRCUNIT_H
