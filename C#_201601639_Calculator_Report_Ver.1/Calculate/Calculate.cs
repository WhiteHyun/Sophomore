using System;

namespace Calculator
{
    public class Calculate : Stack
    {
        public string[] Expression { get; private set; }  //계산기에 입력되는 산술식
        private int Index { get; set; }
        public Calculate()
        {
            Expression = new string[50];    //생성자 호출
            Index = -1;
        }

        #region//식에다가 피연산자나 연산자를 넣어주는 메소드
        public void AddOper(string buff)
        {
            Expression[++Index] = buff;
        }
        #endregion

        #region//식의 마지막 부분을 제거해주는 메소드
        public void DelOper()
        {
            Expression[Index--] = null;
        }
        #endregion

        #region//모든 Stack과 자신이 가지고 있는 식들을 클리어 시켜주는 메소드
        public void AllClear()
        {
            Clear();
            Array.Clear(Expression, '\0', 50);
            Index = -1;
        }
        #endregion

        #region//연산자의 우선순위를 설정해주는 메소드
        private int GetOpPriority(string op)
        {
            int temp_priority = -1;
            switch (op)
            {
                case "!":
                case "^":
                case "cos":
                case "tan":
                case "sin":
                    temp_priority = 4;
                    break;
                case "*":
                case "/":
                case "%":
                case "√":
                    temp_priority = 3;
                    break;
                case "+":
                case "-":
                    temp_priority = 2;
                    break;
                case "(":
                    temp_priority = 1;
                    break;
            }
            return temp_priority;
        }
        #endregion

        #region//두 연산자의 우선순위를 비교하는 메소드, compare과 동일한 결과값이 나온다.
        private int Priority(string operand1, string operand2)
        {
            int prec_op1 = GetOpPriority(operand1);
            int prec_op2 = GetOpPriority(operand2);
            if (prec_op1 > prec_op2)
                return 1;
            else if (prec_op1 < prec_op2)
                return -1;
            else
                return 0;
        }
        #endregion

        #region//parameter가 피연산자인지 연산자인지 구분해주는 메소드
        public bool IsNumber(string str)
        {
            bool compare = false;
            for (int i = 0; i < str.Length; i++)
            {
                if (Char.IsDigit(str[i]) || str[i] == '.')
                {
                    compare = true;
                }
                else
                {
                    compare = false;
                    break;
                }
            }
            return compare;
        }
        #endregion

        #region//중위표기법으로 된 식을 후위표기법으로 변환해주는 메소드
        private void convertToPostExp()  //infix -> postfix  변환
        {
            Index = 0;
            string[] convert_postfix_expression = new string[50];     //후위표기법으로 변환하고 저장할 배열
            string temp_oper = null;        //본래 식에서 하나씩 검사할 때 사용할 변수
            string pop_oper;         //팝해서 나온 수를 저장할 임시변수
            for (int i = 0; Expression[i] != null; i++)
            {
                temp_oper = Expression[i];
                if (IsNumber(temp_oper))           //숫자일 경우   
                {
                    convert_postfix_expression[Index++] = temp_oper;       //후위표기법 배열에 넣음
                }
                else                                    //연산자일 경우
                {
                    switch (temp_oper)
                    {
                        case "(":
                            Push(temp_oper);
                            break;
                        case ")":
                            while (true)
                            {
                                pop_oper = Pop();
                                if (pop_oper == "(")
                                    break;
                                convert_postfix_expression[Index++] = pop_oper;
                            }
                            break;
                        case "+":           //괄호가 아닌
                        case "-":           //연산자일 때
                        case "*":
                        case "/":
                        case "%":
                        case "^":
                        case "√":
                        case "!":
                        case "cos":
                        case "tan":
                        case "sin":
                            while (!isEmpty() && Priority(Stack_operator[Peek], temp_oper) >= 0)   //스택이 비어있지 않으면서 자신의 우선순위가 낮거나 같을 때
                                convert_postfix_expression[Index++] = Pop();        //연산자의 우선순위가 높은 것을 모두 POP하여 넣은다음 자신을 푸쉬 (다음 명령어)
                            Push(temp_oper);
                            break;
                    }
                }
            }
            while (!isEmpty())       //스택 내부에 연산자가 남아있을 경우 POP
                convert_postfix_expression[Index++] = Pop();
            Expression = convert_postfix_expression;    //후위표기한 변수를 본 멤버변수에 저장
            Clear();    //혹시모를 스택의 내부 및 Peek을 클리어시킴
            Index = -1;
        }
        #endregion

        #region//후위표기법으로 된 식을 계산해서 결과 값을 도출해주는 메소드
        private double Calculate_Expression()   //후위표기한 식 계산 메소드
        {
            string temp_oper = null;     //각 연산자 및 피연산자를 하나씩 임시 저장하여 계산할 변수 선언
            double temp_store = 0;     //임시 저장 공간 (정수형)
            double factorial;      //팩토리얼 전용 계산 변수
            string operand1;         //피연산자 1 변수 선언
            string operand2;         //피연산자 2 변수 선언
            for (int i = 0; Expression[i] != null; i++)
            {
                operand1 = null;
                operand2 = null;
                temp_oper = Expression[i];

                if (IsNumber(temp_oper))   //숫자라면
                {
                    Push(temp_oper);       //스택에 쌓음
                }
                else if (temp_oper == "√" || temp_oper == "!" || temp_oper == "cos" || temp_oper == "tan" || temp_oper == "sin")       //연산자라면
                {
                    operand2 = Pop();
                    switch (temp_oper)
                    {
                        case "√":
                            temp_store = Convert.ToDouble(operand2);
                            temp_store = Convert.ToDouble(Math.Sqrt(temp_store));
                            Push(Convert.ToString(temp_store));                     //계산 후에 다시 푸쉬
                            break;
                        case "cos":
                            temp_store = Convert.ToDouble(operand2);
                            temp_store = Convert.ToDouble(Math.Cos(temp_store));
                            Push(string.Format("{0:N2}", temp_store));              //계산 후에 다시 푸쉬

                            break;
                        case "tan":
                            temp_store = Convert.ToDouble(operand2);
                            temp_store = Convert.ToDouble(Math.Tan(temp_store));
                            Push(string.Format("{0:N2}", temp_store));              //계산 후에 다시 푸쉬

                            break;
                        case "sin":
                            temp_store = Convert.ToDouble(operand2);
                            temp_store = Convert.ToDouble(Math.Sin(temp_store));
                            Push(string.Format("{0:N2}", temp_store));              //계산 후에 다시 푸쉬
                            break;
                        case "!":
                            temp_store = Convert.ToDouble(operand2);
                            factorial = 1;
                            for (int j = 1; j <= temp_store; j++)
                            {
                                factorial *= j;
                            }
                            Push(Convert.ToString(factorial));      //팩토리얼 계산 후 푸쉬
                            break;
                    }
                }
                else
                {
                    operand2 = Pop();
                    operand1 = Pop();

                    switch (temp_oper)
                    {
                        case "+":
                            temp_store = Convert.ToDouble(operand1) + Convert.ToDouble(operand2);
                            Push(Convert.ToString(temp_store));
                            break;
                        case "-":
                            temp_store = Convert.ToDouble(operand1) - Convert.ToDouble(operand2);
                            Push(Convert.ToString(temp_store));
                            break;
                        case "*":
                            temp_store = Convert.ToDouble(operand1) * Convert.ToDouble(operand2);
                            Push(Convert.ToString(temp_store));
                            break;
                        case "/":
                            if (operand2 == "0")     //만약 0으로 나누려고 할 경우
                                return -2147483648;         //int형의 최소값을 리턴
                            else
                            {
                                temp_store = Convert.ToDouble(operand1) / Convert.ToDouble(operand2);
                                Push(Convert.ToString(temp_store));
                            }
                            break;
                        case "%":
                            if (operand2 == "0")     //만약 0으로 나누려고 할 경우
                                return -2147483648;         //int형의 최소값을 리턴
                            else
                            {
                                temp_store = Convert.ToDouble(operand1) % Convert.ToDouble(operand2);
                                Push(Convert.ToString(temp_store));
                            }
                            break;
                        case "^":
                            temp_store = Convert.ToDouble(Math.Pow(Convert.ToDouble(operand1), Convert.ToDouble(operand2)));
                            Push(Convert.ToString(temp_store));
                            break;
                    }
                }
            }
            Array.Clear(Expression, '\0', 50);
            return Convert.ToDouble(Pop());
        }
        #endregion

        #region//전체적인 실행 메소드
        public double Run()
        {
            convertToPostExp();
            return Calculate_Expression();
        }
        #endregion
    }
}