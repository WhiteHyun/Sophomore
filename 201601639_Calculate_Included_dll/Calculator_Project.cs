using System;
using System.Windows.Forms;
using Calculator;

namespace _201601639_Calculate_Included_dll
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
}
