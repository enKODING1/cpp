#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void) {
  Intern intern;
  Bureaucrat rich("Bender", 1);
  Bureaucrat poor("Fry", 148);

  AForm *form = intern.makeForm("robotomy request", "Bender");

  poor.signForm(*form);   // 등급 부족 -> 서명 실패
  rich.executeForm(*form); // 서명 안 됨 -> FormNotSignedException

  rich.signForm(*form);
  poor.executeForm(*form); // 서명 됨, 등급 부족 -> GradeTooLowException
  rich.executeForm(*form); // 정상 실행

  try {
    delete intern.makeForm("time travel", "nobody");
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }

  delete form;
  return 0;
}
