#include <iostream>
#include <TFormula.h>

int main() {
  setlocale(LC_ALL, "Russian");

  TStack <int> stack(3);
  stack.Push(1);
  stack.Push(2);
  cout << "Размер стека " << stack.Size() << endl;
  cout << "Верхний элемент стека stack  " << stack.TopElem() << endl;
  stack.Pop();
  stack.Pop();
  stack.Push(3);
  cout << "Верхний элемент стека stack  " << stack.TopElem() << endl;
  cout << "Размер стека stack " << stack.Size() << endl;
  stack.Pop();

  if (stack.isEmpty()) {
    cout << "Стек пуст\n" << endl;
  }
  else {
    cout << "Стек не пуст\n" << endl;
  }

  TStack <int> stack2(4);
  stack2.Push(111);
  stack2.Push(180);
  stack2.Push(228);
  stack2.Push(337);
  cout << "Верхний элемент стека stack2  " << stack2.TopElem() << endl;
  cout << "Размер стека stack2 " << stack2.Size() << endl;
  TStack <int> pt3(stack2);
  cout << "Верхний элемент стека pt3  " << pt3.TopElem() << endl;
  cout << "Размер стека pt3 " << pt3.Size() << endl;


  string exprStr;
  cout << "Введите инфиксное выражение без пробелов " << endl;
  cin >> exprStr;
  TFormula expr(exprStr);
  cout << "Инфиксное выражение:  " << expr.GetInfix() << endl;
  cout << "Постфиксное выражение: " << expr.GetPostfix() << endl;
  vector <char> operands = expr.GetOperands();
  map <char, double> values;
  double value;
  for (const auto& operand : operands)
  {
    cout << "Введите значение для операнда " << operand << endl;
    cin >> value;
    values[operand] = value;
  }

  cout << "Результат = " << expr.Calculate(values) << endl;

  return 0;
}