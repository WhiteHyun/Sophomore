using System;
using System.Windows.Forms;
using Calculator;

namespace ch13_계산기만들기
{
    public partial class 홍승현계산기 : Form
    {
        private const int ERROR = -2147483648;
       
        // 계산기에서 사용할 전역변수 선언
        Calculate calculator = new Calculate();    //계산 전용 클래스 선언
        string buff = "";         // 임시 보관 할 변수
        string output = "";      // 임시 출력 할 변수
        double result;          // 결과 값 저장할 변수
        public 홍승현계산기()
        {
            InitializeComponent();
        }
        private void bt_num_click(object sender, MouseEventArgs e)
        {
            Button btn = sender as Button;    //숫자 키 중 어느 것이 눌러졌는지를 저장
            buff += btn.Text;
            output += btn.Text;
            textBox1.Text = output;
            
        }

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
            else if(btn.Text != ")" && btn.Text !="(")
            {                   //연산자 선택했다가 또 연산자를 선택했을 경우 최근에 누른 연산자로 바꿈
                calculator.DelOper();
                calculator.AddOper(btn.Text);
                output = textBox1.Text.Substring(0, textBox1.Text.Length - 1);
                output += btn.Text;
                textBox1.Text = output;
            }
            else
            {
                calculator.AddOper(btn.Text);
                output += btn.Text;
                textBox1.Text = output;
            }
            buff = "";
        }

        private void bt_clear_click(object sender, MouseEventArgs e)
        {
            textBox1.Text = "";
            buff = "";
            output = "";
            result = 0.0;
            calculator.AllClear();
        }

        private void 홍승현계산기_Load(object sender, EventArgs e)
        {
            textBox1.Text = output;
        }

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
                output = "오류";        //ERROR 출력
                textBox1.Text = output;     //하기위한 코드들
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
    }
}
