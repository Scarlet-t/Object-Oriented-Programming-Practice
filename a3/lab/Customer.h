#ifndef SENECA_CUSTOMER_H
#define SENECA_CUSTOMER_H
namespace seneca {
	class Car;
	class Customer {
		int m_id;
		char* m_name;
		const Car* m_car;
	public:
		bool isEmpty() const;
		void setEmpty();
		void deallocateMemory();
		void set(int customerId, const char* name, const Car* car);
		void display() const;
		const Car& car() const;
	};
}
#endif