
#include "Form.hpp"

// Constructors

Form::Form() : name_(""), signed_(false), grade_sign_(1), grade_execute_(1) {}

Form::Form(std::string name, int grade_for_signing, int grade_for_execution)
    : name_(name),
      signed_(false),
      grade_sign_(grade_for_signing),
      grade_execute_(grade_for_execution) {
  if (grade_for_signing > 150 || grade_for_execution > 150) {
    this->~Form();
    throw GradeTooLowException();
  }
  if (grade_for_signing < 1 || grade_for_execution < 1) {
    this->~Form();
    throw GradeTooHighException();
  }
}

Form::Form(const Form &copy)
    : name_(copy.getName()),
      signed_(copy.getSignedStatus()),
      grade_sign_(copy.getGradeSign()),
      grade_execute_(copy.getGradeExecute()) {}

// Destructor
Form::~Form() {}

// Getters & Setters
bool Form::getSignedStatus() const { return this->signed_; }

std::string Form::getName() const { return this->name_; }

int Form::getGradeSign() const { return this->grade_sign_; }

int Form::getGradeExecute() const { return this->grade_execute_; }

// Functions
void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (this->grade_sign_ < bureaucrat.getGrade()) throw GradeTooLowException();
  this->signed_ = true;
}

// Exceptions
const char *Form::GradeTooHighException::what() const throw() {
  return "grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Form& form) {
  out << "Name: " << form.getName() << std::endl
			<< "Signed: " << (form.getSignedStatus() ? "yes" : "no") << std::endl
			<< "Grade required for signing: " << form.getGradeSign() << std::endl
			<< "Grade required for executing: " << form.getGradeExecute() << std::endl; 
  return out;
}