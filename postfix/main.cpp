#include <iostream>
#include <TFormula.h>

int main() {
  setlocale(LC_ALL, "Russian");

  TStack <int> stack(3);
  stack.Push(1);
  stack.Push(2);
  cout << "������ ����� " << stack.Size() << endl;
  cout << "������� ������� ����� stack  " << stack.TopElem() << endl;
  stack.Pop();
  stack.Pop();
  stack.Push(3);
  cout << "������� ������� ����� stack  " << stack.TopElem() << endl;
  cout << "������ ����� stack " << stack.Size() << endl;
  stack.Pop();

  if (stack.isEmpty()) {
    cout << "���� ����\n" << endl;
  }
  else {
    cout << "���� �� ����\n" << endl;
  }

  TStack <int> stack2(4);
  stack2.Push(111);
  stack2.Push(180);
  stack2.Push(228);
  stack2.Push(337);
  cout << "������� ������� ����� stack2  " << stack2.TopElem() << endl;
  cout << "������ ����� stack2 " << stack2.Size() << endl;
  TStack <int> pt3(stack2);
  cout << "������� ������� ����� pt3  " << pt3.TopElem() << endl;
  cout << "������ ����� pt3 " << pt3.Size() << endl;


  string exprStr;
  cout << "������� ��������� ��������� ��� �������� " << endl;
  cin >> exprStr;
  TFormula expr(exprStr);
  cout << "��������� ���������:  " << expr.GetInfix() << endl;
  cout << "����������� ���������: " << expr.GetPostfix() << endl;
  vector <char> operands = expr.GetOperands();
  map <char, double> values;
  double value;
  for (const auto& operand : operands)
  {
    cout << "������� �������� ��� �������� " << operand << endl;
    cin >> value;
    values[operand] = value;
  }

  cout << "��������� = " << expr.Calculate(values) << endl;

  return 0;
}