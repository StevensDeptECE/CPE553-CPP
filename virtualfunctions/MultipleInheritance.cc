#include <cstdint>

class MushuChicken : public Mushu, public Chicken {};
class GarlicChicken : public Garlic, public Chicken {};


class Employee {
private:
	uint64_t ssn;
public:
};

class Secretary : public virtual Employee {
public:
	void writeMemo();
};

class Temp : public virtual Employee {
private:
	Date term;
public:
	Temp(Date term) : term(term) {}
};

class TempSecretary : public Secretary, public Temp {

};

/*
without virtual inheritance
 +--------------------+
 | Employee           |
 +                    |
 | Secretary          |
 +--------------------+
 | Employee           |
 |                    |
 | Temp               |
 +--------------------+

with virtual
 +--------------------+
 + Employee*          |
 | Secretary          |
 +--------------------+
 | Employee*          |
 |                    |
 | Temp               |
 | Employee           |
 +--------------------+


 */

	
