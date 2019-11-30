using System;
using System.Windows.Forms;

namespace _201601639_Calculate_Notdll
{
    public partial class Calculator_Project : Form
    {
        private const int ERROR = -2147483648;

        // 계산기에서 사용할 전역변수 선언
        Calculate calculator = new Calculate();    //계산 클래스 선언
        string buff = "";         // 임시 보관 할 변수
        string output = "";      // 임시 출력 할 변수
        double result;          // 결과 값 저장할 변수
        public Calculator_Project()
        {
            InitializeComponent();
        }
        #region 피연산자 버튼 클릭 시
        private void bt_num_click(object sender, MouseEventArgs e)
        {
            Button btn = sender as Button;    //숫자 키 중 어느 것이 눌러졌는지를 저장
            buff += btn.Text;
            output += btn.Text;
            textBox1.Text = output;

        }
        #endregion

        #region 연산자 버튼 클릭 시
        private void bt_oper_click(object sender, MouseEventArgs e)
        {
            Button btn = sender as Button;
            if (calculator.IsNumber(buff))  //연산자 전에 피연산자 일 경우
            {
                calculator.AddOper(buff);
                calculator.AddOper(btn.Text);
                output += btn.Text;
                textBox1.Text = output;
            }
            else if (btn.Text != ")" && btn.Text != "(")  //괄호가 아닌 연산자를 입력 받았을 때
            {
                if (calculator.Expression[0] == null)
                {                                   //입력창 처음에 연산자를 입력하려 할 때
                    if (btn.Text == "-")            // '-' 를 입력받은 경우
                    {
                        buff += btn.Text;
                        output += btn.Text;
                        textBox1.Text = output;
                        return;
                    }
                    else                            // '-'를 제외한 연산자일 경우 자동으로 0을 추가함
                    {
                        buff = "0";
                        calculator.AddOper(buff);
                        calculator.AddOper(btn.Text);
                        output = "0" + btn.Text;
                        textBox1.Text = output;
                    }
                }
                else                   //연산자 선택했다가 또 연산자를 선택했을 경우 
                {
                    if (calculator.IsNumber(calculator.ShowStringLastSecond()))  //입력하려는 연산자 전에도 연산자가 아닐 경우만 최근에 누른 연산자로 바꿈
                    {

                        calculator.DelOper();
                        calculator.AddOper(btn.Text);
                        output = textBox1.Text.Substring(0, textBox1.Text.Length - 1);  //기존 연산자를 제거해서 저장
                        output += btn.Text;
                        textBox1.Text = output;
                    }
                    else if (calculator.ShowStringLast() == ")")       //닫힌괄호일 경우
                    {
                        calculator.AddOper(btn.Text);
                        output += btn.Text;
                        textBox1.Text = output;
                    }
                }
            }
            else            //괄호일 경우
            {
                if (!calculator.IsNumber(calculator.ShowStringLast()))  //그 전 문자가 숫자가 아닐 경우만 넣음
                {
                    calculator.AddOper(btn.Text);
                    output += btn.Text;
                    textBox1.Text = output;
                }
            }
            buff = "";
        }
        #endregion

        #region 클리어 버튼 클릭 시
        private void bt_clear_click(object sender, MouseEventArgs e)
        {
            textBox1.Text = "";
            buff = "";
            output = "";
            result = 0.0;
            calculator.AllClear();
        }
        #endregion

        #region 로드

        private void 홍승현계산기_Load(object sender, EventArgs e)
        {
            textBox1.Text = output;
        }
        #endregion

        #region 계산버튼(=) 클릭 시
        private void bt_calc_click(object sender, MouseEventArgs e)
        {
            Button btn = sender as Button;
            if (calculator.IsNumber(buff))
            {
                calculator.AddOper(buff);
            }
            result = calculator.Run();      //주어진 식들을 계산하여 결과값 저장
            if (result == ERROR)        //계산 중 오류 발생 조건문
            {
                output = "오류";        //ERROR 출력하기 위해 output 저장
                textBox1.Text = output; //ERROR 출력
                buff = "";              //버퍼 비움
                output = "";            //아웃풋 변수도 초기화
            }
            else
            {
                output += btn.Text + result.ToString();
                textBox1.Text = output;
                buff = Convert.ToString(result);
                output = buff;
            }
        }
        #endregion
    }
    #region 스택
    public class Stack
    {
        private const string ERROR = "접근할 수 없습니다.";

        public int Peek { get; private set; }       //스택의 최상위를 가리킴
        public string[] Stack_operator { get; private set; }    //스택 배열

        #region 스택 생성자, 멤버 변수 초기화
        public Stack()
        {
            Stack_operator = new string[20];       //임의로 100만큼의 크기 할당
            Peek = -1;                              //-1로 초기화
        }
        #endregion

        #region Push
        protected void Push(string temp_oper)
        {
            if (Peek != 20)
            {
                Stack_operator[++Peek] = temp_oper;     //Peek + 1 의 공간에 연산자 푸쉬
            }
            else
            {
                Console.WriteLine(ERROR);
            }
        }
        #endregion

        #region Pop
        protected string Pop()
        {
            string temp_pop = null;
            if (Peek != -1)
            {
                temp_pop = Stack_operator[Peek];
                Stack_operator[Peek--] = null;
            }
            else
            {
                Console.WriteLine(ERROR);
            }
            return temp_pop;
        }
        #endregion

        #region Clear
        public void Clear()
        {
            Array.Clear(Stack_operator, '\0', 20);
            Peek = -1;
        }
        #endregion

        #region isEmpty
        public bool isEmpty()
        {
            if (Peek == -1)
                return true;
            else
                return false;
        }
        #endregion
    }
    #endregion

    #region 전반적인 계산 시스템
    public class Calculate : Stack
    {
        public string[] Expression { get; private set; }  //계산기에 입력되는 산술식
        private int Index { get; set; }
        public Calculate()
        {
            Expression = new string[50];    //생성자 호출
            Index = -1;
        }
        #region 가장 최근에 입력된 문자열을 반환 해주는 메소드
        public String ShowStringLast()
        {
            if (Index < 0)
                return null;
            return Expression[Index];
        }
        #endregion

        #region 최근 입력된 문자열의 두번째 위치를 반환 해주는 메소드
        public String ShowStringLastSecond()
        {
            if (Index - 1 < 0)
                return null;

            return Expression[Index - 1];
        }
        #endregion

        #region 식에다가 피연산자나 연산자를 넣어주는 메소드
        public void AddOper(string buff)
        {
            Expression[++Index] = buff;
        }
        #endregion

        #region 식의 마지막 부분을 제거해주는 메소드
        public void DelOper()
        {
            Expression[Index--] = null;
        }
        #endregion

        #region 모든 Stack과 자신이 가지고 있는 식들을 클리어 시켜주는 메소드
        public void AllClear()
        {
            Clear();
            Array.Clear(Expression, '\0', 50);
            Index = -1;
        }
        #endregion

        #region 연산자의 우선순위를 설정해주는 메소드
        private int GetOpPriority(string op)
        {
            int temp_priority = -1;
            switch (op)
            {
                case "!":       //2*3! 을 계산했을 때 우선순위가 같다면 6!이 되어버리기 때문
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

        #region 두 연산자의 우선순위를 비교하는 메소드, compare과 동일한 결과값이 나온다.
        private int Compare_Priority(string operand1, string operand2)
        {
            int prec_op1 = GetOpPriority(operand1);
            int prec_op2 = GetOpPriority(operand2);
            if (prec_op1 > prec_op2)            //왼쪽 연산자의 우선순위가 높으면 1을 반환
                return 1;
            else if (prec_op1 < prec_op2)       //오른쪽 연산자의 우선순위가 높으면 -1을 반환
                return -1;
            else                                //서로의 연산자 우선순위가 같으면 0을 반환
                return 0;
        }
        #endregion

        #region parameter가 피연산자인지 연산자인지 구분해주는 메소드
        public bool IsNumber(string str)
        {
            bool compare = false;
            for (int i = 0; i < str.Length; i++)
            {
                if (Char.IsDigit(str[i]) || str[i] == '.')  //피연산자일 경우와, 소수 구분을 위해 조건에 넣어둠.
                {
                    compare = true;
                }
                else if (str[i] == '-')
                {
                    continue;
                }
                else                   //연산자일 경우
                {
                    compare = false;
                    break;
                }
            }
            return compare;
        }
        #endregion

        #region 중위표기법으로 된 식을 후위표기법으로 변환해주는 메소드
        //*********************************후위표기법 변경 규칙***************************************************
        // 1. 숫자가 나오면 그대로 저장한다.
        // 2. '('나오면 스택에 push한다.
        // 3. * / 나오면 스택에 push한다.
        // 4. + - 연산이 나오면 여는 괄호('('), 여는 괄호가 없다면 스택의 끝까지 저장하고 그 연산자를 스택에 push한다.
        // 5. 닫는 괄호(')')가 나오면 여는 괄호('(')가 나올때까지 pop하여 저장한다.
        //*******************************************************************************************************
        private void convertToPostExp()  //infix -> postfix  변환
        {
            Index = 0;
            string[] convert_postfix_expression = new string[50];     //후위표기법으로 변환하고 저장할 배열
            string check_oper = null;        //본 식에서 연산자, 피연산자를 하나씩 검사할 때 사용할 변수
            string pop_oper;         //팝해서 나온 수를 저장할 임시변수
            for (int i = 0; Expression[i] != null; i++)
            {
                check_oper = Expression[i];
                if (IsNumber(check_oper))           //숫자일 경우   
                {
                    convert_postfix_expression[Index++] = check_oper;       //후위표기법 배열에 넣음
                }
                else                                    //연산자일 경우
                {
                    switch (check_oper)
                    {
                        case "(":           //open parentheses 일 때는 Push함.
                            Push(check_oper);
                            break;
                        case ")":           //close parentheses 일 때
                            while (true)
                            {
                                pop_oper = Pop();
                                if (pop_oper == "(")    //open parentheses를 만날 때 까지 Pop
                                    break;
                                convert_postfix_expression[Index++] = pop_oper; //Pop 한 것을 후위표기법 저장하는 배열에 넣음
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
                            while (!isEmpty() && Compare_Priority(Stack_operator[Peek], check_oper) >= 0)   //스택이 비어있지 않으면서 자신의 우선순위가 낮거나 같을 때
                                convert_postfix_expression[Index++] = Pop();        //연산자의 우선순위가 높은 것을 모두 POP하여 넣은다음 자신을 푸쉬 (다음 명령어)
                            Push(check_oper);
                            break;
                    }
                }
            }
            while (!isEmpty())       //스택 내부에 연산자가 남아있을 경우 POP
                convert_postfix_expression[Index++] = Pop();
            Expression = convert_postfix_expression;    //후위표기한 변수를 본 멤버변수에 저장
            Clear();    //혹시모를 스택의 내부 및 Peek을 클리어시킴
            Index = -1; //인덱스도 초기화
        }
        #endregion

        #region 후위표기법으로 된 식을 계산해서 결과 값을 도출해주는 메소드
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
                            Push(string.Format("{0:N2}", temp_store));                     //계산 후에 다시 푸쉬
                            break;
                        case "cos":
                            temp_store = Convert.ToDouble(operand2);
                            temp_store = Convert.ToDouble(Math.Cos(temp_store * Math.PI / 180));
                            Push(string.Format("{0:N2}", temp_store));              //계산 후에 다시 푸쉬

                            break;
                        case "tan":
                            temp_store = Convert.ToDouble(operand2);
                            temp_store = Convert.ToDouble(Math.Tan(temp_store * Math.PI / 180));
                            Push(string.Format("{0:N2}", temp_store));              //계산 후에 다시 푸쉬

                            break;
                        case "sin":
                            temp_store = Convert.ToDouble(operand2);
                            temp_store = Convert.ToDouble(Math.Sin(temp_store * Math.PI / 180));
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

        #region 전체적인 실행 메소드
        public double Run()
        {
            convertToPostExp();
            return Calculate_Expression();
        }
        #endregion
    }
    #endregion
}
