class Employee {
private:
	long ssn;
};

class Secretary : public Employee {
private:
  int yearsOfService;
public:
	signDocument();
};

class Temp : public Employee {
private:
	int termDate;
public:
};

class TempSecretary : public Secretary, public Temp {

};

Employee:
+-------------+
ssn
+-------------+

Secretary:
+-------------+
ssn
yearsofserice
+-------------+

Temp:
+-------------+
ssn
termdate
+-------------+

TempSecretary
+-------------+
ssn
yearsofserice
ssn
termdate
+-------------+

class Employee {
private:
	long ssn;
};

class Secretary : public virtual Employee {
private:
  int yearsOfService;
public:
	signDocument();
};

class Temp : public  virtual Employee {
private:
	int termDate;
public:
};

class TempSecretary : public Secretary, public Temp {

};

Secretary:
+-------------+
Employee*-------\
yearsofserice   |
+-------------+ |
   ssn      <--/
+-------------+

Temp:
+-------------+
Employee*
termdate
+-------------+
   ssn      
+-------------+

TempSecretary
+-------------+
Employee*
yearsofserice
Employee*
termdate
+-------------+
ssn
+-------------+



















class Chicken {};
class Beef {};
class Shrimp {};


class Mushu {};
class Garlic {};


class MushuChicken : public Chicken, public Mushu {};

