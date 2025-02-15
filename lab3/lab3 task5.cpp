#include<iostream>
using namespace std;
class Employee{
	string name;
	int m_salary;
	float taxPercentage;
	public:
		void get_data(string n, int s, float tp)
		{
			name=n;
			m_salary=s;
			taxPercentage=tp;
		}
		void salary_after_tax()
		{
			cout<<"reamaining salary after tax reduction: Rs."<<(m_salary-(m_salary*(taxPercentage/100)))<<endl;
		}
		void update_tax_percentage()
		{
			float upd;
			cout<<"enter updated tax percentage: ";
			cin>>upd;
			taxPercentage=upd;
			cout<<"remaining salary after updated tax percentage reduction:  Rs."<<m_salary-(m_salary*(upd/100));
			
		}
};
int main()
{
	string n;
	int s;
	float tp;
	Employee e1;
	cout<<"enter name: ";
	cin>>n;
	cout<<"enter monthly salary: ";
	cin>>s;
	cout<<"enter tax percentage: ";
	cin>>tp;
	e1.get_data(n,s,tp);
	e1.salary_after_tax();
	e1.update_tax_percentage();
	
}
