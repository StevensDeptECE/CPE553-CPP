template<typename T>
class Vector {
public:
	Vector();
	Vector(int initialCapacity);
	~Vector();
	Vector(const Vector& orig);
	Vector& operator =(const Vector& orig);

	class ConstIterator {
	public:
		bool operator !();
		bool operator++();
		const T& operator*();
	};
	
	class Iterator {
	public:
		bool operator !();
		bool operator++();
		T& operator*();
	};
	class ReverseIterator {
	public:
		bool operator !();
		bool operator++();
		const T& operator*();
	};

	Iterator begin();
	ReverseIterator end();
	
  
	
	
};
