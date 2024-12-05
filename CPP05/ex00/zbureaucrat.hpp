ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>

#define DEFAULT "\033[39m"
#define BLACK "\033[30m"
#define GREY "\033[90m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"
#define MAGENTA "\033[35m"

class Bureaucrat {
 public:
  // Constructors
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &copy);

  // Destructor
  ~Bureaucrat();

  // Getters & Setters
  std::string getName(void) const;
  int getGrade(void) const;
  void setGrade(int grade);

  // Functions
  void incrementGrade(void);
  void decrementGrade(void);

  // Exceptions
  class GradeTooHighException : public std::exception {
	 public:
		virtual const char *what() const throw();
	};
	
  class GradeTooLowException: public std::exception {
	 public:
		virtual const char *what() const throw();
	};

 private:
  // Default constructor and copy assignment operator overload private, because
  // they make no sense here (still adhering to the norm...)
  Bureaucrat();
  Bureaucrat &operator=(const Bureaucrat &);
	
  const std::string name_;
  int grade_;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif