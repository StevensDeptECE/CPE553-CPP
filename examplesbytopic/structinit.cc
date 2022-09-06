#include <cstdint>
#include <cstring>
using namespace std;

struct NamedLocationData {
  uint16_t offset;
  char stateName[21];
  float lat;
  float lon;
  uint32_t population;

	NamedLocationData(uint16_t offset, const char stateName[21],
										float lat, float lon, uint32_t population)
		:	offset(offset), lat(lat), lon(lon), population(population) {
		strncpy(this->stateName, stateName, 21);
	}

};

int main() {
	uint16_t nameOffset = 0;
	char stateName[21] = "New York";
	float lat = 40;
	float lon = -74;
	uint32_t population = 8000000;

	#if 0
	NamedLocationData temp = NamedLocationData
		{
		 nameOffset, stateName, lat, lon, population
		};
	#endif
	
	NamedLocationData temp( nameOffset, stateName, lat, lon, population);
		
}
