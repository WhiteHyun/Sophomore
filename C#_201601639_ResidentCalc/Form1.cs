using System;
using System.Windows.Forms;
using HSH_Resident_Operation;

namespace _201601639_주민과제
{

    public partial class Form_Resident : Form
    {
        private const int NOT_ERROR = 0;
        private const int BIRTH_ERROR = 1;
        private const int GENDER_ERROR = 2;
        private const int LENGTH_ERROR = 3;
        private const int CHAR_ERROR = 4;
        public Form_Resident()
        {
            InitializeComponent();
        }
        
        private void btn_Return_Click(object sender, EventArgs e)
        {
            string ResidentNumber = txt_FrontResidentNumber.Text + txt_LastResidentNumber.Text;
            ResidentNumber_Calc resident = new ResidentNumber_Calc(ResidentNumber);
            switch(resident.isError())
            {
                case BIRTH_ERROR:
                    MessageBox.Show("생년월일의 오류가 있습니다. 다시 작성해 주세요.");
                    txt_FrontResidentNumber.Focus();
                    break;
                case GENDER_ERROR:
                    MessageBox.Show("성별의 오류가 있습니다. 주민등록번호 뒷 7자리를 다시 작성해 주세요.");
                    txt_LastResidentNumber.Focus();
                    break;
                case LENGTH_ERROR:
                    MessageBox.Show("맞지 않은 주민등록번호의 길이입니다. 다시 작성해 주세요.");
                    txt_FrontResidentNumber.Focus();
                    break;
                case CHAR_ERROR:
                    MessageBox.Show("문자 오류입니다. 숫자만 입력해주세요!");
                    txt_FrontResidentNumber.Focus();
                    break;
                case NOT_ERROR:
                    txt_Year.Text = resident.Year.ToString();
                    txt_Month.Text = resident.Month.ToString();
                    txt_Day.Text = resident.Day.ToString();
                    txt_Age.Text = resident.Age.ToString();
                    txt_Sex.Text = resident.Gender;
                    break;
            }
        }

        private void txt_FrontResidentNumber_MouseClick(object sender, MouseEventArgs e)
        {
            txt_FrontResidentNumber.Text = "";
        }

        private void txt_LastResidentNumber_MouseClick(object sender, MouseEventArgs e)
        {
            txt_LastResidentNumber.Text = "";
        }

        private void txt_FrontResidentNumber_KeyPress(object sender, KeyPressEventArgs e)
        {
            if(!(char.IsDigit(e.KeyChar) || e.KeyChar == Convert.ToChar(Keys.Back)))    //문자를 받을 때(BackSpace 제외)
            {
                MessageBox.Show("숫자만 입력하세요.");
                e.Handled = true;
            }
            else if (txt_FrontResidentNumber.TextLength > 5 && !(e.KeyChar == Convert.ToChar(Keys.Back)))   //6자리 이상 적을 때(BackSpace 제외)
            {
                MessageBox.Show("6자리까지만 입력 가능합니다.");
                e.Handled = true;
            }
            else if (txt_FrontResidentNumber.TextLength == 5 && txt_FrontResidentNumber.Text != "앞 6자리" && e.KeyChar != Convert.ToChar(Keys.Back))
            {
                txt_LastResidentNumber.Focus();
            }
        }

        private void txt_LastResidentNumber_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!(char.IsDigit(e.KeyChar) || e.KeyChar == Convert.ToChar(Keys.Back)))    //문자를 받을 때(BackSpace 제외)
            {
                if (e.KeyChar == Convert.ToChar(Keys.Return))
                    btn_Return.Focus();
                else
                {
                    MessageBox.Show("숫자만 입력하세요.");
                    e.Handled = true;
                }
            }
            else if (txt_LastResidentNumber.TextLength > 6 && !(e.KeyChar == Convert.ToChar(Keys.Back)))   //6자리 이상 적을 때(BackSpace 제외)
            {
                MessageBox.Show("7자리까지만 입력 가능합니다.");
                e.Handled = true;
            }
            else if (txt_LastResidentNumber.TextLength == 6 && txt_LastResidentNumber.Text != "뒷 7자리" && e.KeyChar != Convert.ToChar(Keys.Back))
            {
                btn_Return.Focus();
            }
        }
    }
}
