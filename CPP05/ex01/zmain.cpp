
#include "Bureaucrat.hpp"
#include "Form.hpp"


int main(void) {
	std::cout << RED << "----- invalid form creation -----" << std::endl << std::endl;
	try {
		Form f1("Something", 1, 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Form f2("Something", 1, 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl << GREEN << "----- trying to sign some forms -----" << std::endl << std::endl;
	
	Bureaucrat abby("Abby", 75);
	Form f3("Average form", 75, 150);
	Form f4("Presidential form", 74, 150);
	Form f5(f3);
	Form f6(f4);

	std::cout << f3 << std::endl
						<< f4 << std::endl
						<< f5 << std::endl
						<< f6 << std::endl;
	
	abby.signForm(f3);
	abby.signForm(f4);
	
	try {
		f4.beSigned(abby);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	abby.signForm(f5);
	abby.signForm(f6);

	try {
		f6.beSigned(abby);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << f3 << std::endl
						<< f4 << std::endl
						<< f5 << std::endl
						<< f6 << std::endl;
}