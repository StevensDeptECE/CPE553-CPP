enum Color { BLACK, WHITE }; // old style C, C++, not type-safe BLACK=0, WHITE=1
enum Decision {YES, NO, MAYBE }; //YES = 0, NO = 1, MAYBE = 2

//bad idea:
Decision x = BLACK; // compiler doesn't check, they are both really int

enum class DataType {
	UINT1,
		UINT2,
		UINT4,
		UINT8,
		UINT16,
		FLOAT,
		DOUBLE,
		COUNT
		};

DataType y = DataType::UINT4; // and it's typesafe

const uint32_t sizes[DataType::COUNT] = { // initialized to zeros (global
	1,
	2,
	4,
	8,
	16
};

class DataTypeInfo {
private:
	DataType type;
	uint32_t size;
public:
	DataTypeInfo( DataType type, uint32_t size ) : type(type), size(size) {}
};

DataTypeInfo info = {
	{UINT1, 1},
	{UINT2, 2},
	{UINT4, 4},
	{UINT8, 8},
	{UINT16, 16},
	{FLOAT,  4},
	{DOUBLE, 8}
};
	


		
