using System;
using System.Drawing;
using System.Windows.Forms;

namespace _201601639_RandomProject
{
    public partial class HomeWork : Form
    {
        private Random rand = new Random();
        private GroupBox[] GB = new GroupBox[3]; // 그룹 박스 
        private RadioButton[,] Example_RB = new RadioButton[5, 5];  // 보기(RADIOBUTTON, TEXT)
        private PictureBox[] Example_PB = new PictureBox[5];  // 보기    (Image)
        private PictureBox Quiz_PB = new PictureBox();  // 문제   (Image)

        private Label lbScore = new Label();     // 점수 표시 Label  
        private Button button = new Button();  // Button 
        private int score = 0;                          // 점수 변수
        private int[] quiz_rand = new int[6] { -1, -1, -1, -1, -1, 0 };
        private int[] example_rand = new int[4] { -1, -1, -1, -1 };
        private string aa = "[문제 ";   // 1]  은 소스에서 추가 해야 함
        private string[,] Question = new string[5, 7] {
            {"우리나라 수도는?", "서울", "인천", "부산", "광주", "서울", "TT"},
            { "인천대학 위치는?", "인천", "송도", "서울", "청주", "송도", "TT"},
            { "인천의 산은?", "백두산", "한라산", "지리산", "계양산", "계양산", "TT"},
            { "다음 중에서 동양인은?", "Images/Girl1.jpg", "Images/Girl2.jpg", "Images/Girl3.jpg", "Images/Girl4.jpg", "Images/Girl4.jpg", "TI"},
            { "아래 사진은 누구인가?", "아이돌", "아이큐", "아이비", "아이유", "아이유", "IT"}};

        public HomeWork()
        {
            InitializeComponent();
            int example_rand_num = 0;   //보기 랜덤 숫자 임시 저장
            for (int i = 0; i < 5; i++)
                quiz_rand[i] = Generate_RandomNumber(quiz_rand, i, 5);


            #region  //점수 표시할 Label 동적으로 생성
            lbScore = new Label();
            this.lbScore.Name = "lbScore";
            this.lbScore.Text = "score";
            this.lbScore.Size = new Size(90, 30);
            this.lbScore.Location = new System.Drawing.Point(30, 550);
            this.Controls.Add(lbScore);
            #endregion

            #region //채점버튼 생성
            this.button.Name = "btnSubmit";
            this.button.Text = "채점하기";
            this.button.Size = new Size(90, 30);
            this.button.AutoSize = true;
            this.button.Location = new System.Drawing.Point(220, 550);
            this.button.Click += new EventHandler(button_Click);
            this.Controls.Add(button);
            #endregion

            #region  //Group Box 문제 생성 및 바인딩
            for (int n = 0; n < 3; n++)
            {
                int randnum = quiz_rand[n];
                GB[n] = new GroupBox();
                this.GB[n].AutoSize = true;
                if (Question[randnum, 6] == "TT")
                {
                    if (n == 0)
                        this.GB[n].Location = new System.Drawing.Point(10, 10 + (n * 80));
                    else
                        this.GB[n].Location = new System.Drawing.Point(10, ProblemTypeAndHeight(Question, quiz_rand, n - 1));
                }
                else if (Question[randnum, 6] == "IT")
                {
                    if (n == 0)
                        this.GB[n].Location = new System.Drawing.Point(10, 10 + (n * 130));
                    else
                        this.GB[n].Location = new System.Drawing.Point(10, ProblemTypeAndHeight(Question, quiz_rand, n - 1));
                }
                else if (Question[randnum, 6] == "TI")
                {
                    if (n == 0)
                        this.GB[n].Location = new System.Drawing.Point(10, 10 + (n * 130));
                    else
                        this.GB[n].Location = new System.Drawing.Point(10, ProblemTypeAndHeight(Question, quiz_rand, n - 1));
                }
                this.GB[n].Size = new System.Drawing.Size(200, 10);
                this.GB[n].TabIndex = 0;
                this.GB[n].TabStop = false;
                this.GB[n].Text = aa + (n + 1) + "] " + Question[randnum, 0];
                this.Controls.Add(GB[n]);
                //문제 생성 끝

                switch (Question[randnum, 6])
                {
                    case "TT":
                        for (int i = 0; i < 5; i++)
                        {
                            Example_RB[randnum, i] = new RadioButton();
                            if (i < 4)
                            {
                                example_rand[i] = Generate_RandomNumber(example_rand, i, 4);
                                example_rand_num = example_rand[i];
                                this.Example_RB[randnum, i].Text = Question[randnum, example_rand_num + 1];
                            }
                            else
                            {
                                this.Example_RB[randnum, i].Text = Question[randnum, i + 1];
                                this.Example_RB[randnum, i].Visible = false;    //정답 숨김
                            }
                            this.Example_RB[randnum, i].Location = new System.Drawing.Point(30 + (i * 70), 30);
                            this.Example_RB[randnum, i].Size = new System.Drawing.Size(60, 15);
                            this.Controls.Add(Example_RB[randnum, i]);
                            this.GB[n].Controls.Add(this.Example_RB[randnum, i]);
                        }
                        break;
                    case "TI":
                        for (int i = 0; i < 5; i++)
                        {
                            Example_RB[randnum, i] = new RadioButton();
                            this.Example_RB[randnum, i].Size = new System.Drawing.Size(15, 15);
                            this.Controls.Add(Example_RB[randnum, i]);
                            this.GB[n].Controls.Add(this.Example_RB[randnum, i]);
                            Example_PB[i] = new PictureBox();
                            this.Example_PB[i].Size = new System.Drawing.Size(100, 100);
                            this.Example_PB[i].SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
                            this.GB[n].Controls.Add(this.Example_PB[i]);

                            if (i < 4)  //4보다 작을 때
                            {
                                if (i < 2)
                                {
                                    this.Example_RB[randnum, i].Location = new System.Drawing.Point(30 + (i * 150), 60);
                                    this.Example_PB[i].Location = new System.Drawing.Point(50 + (i * 150), 20);
                                }
                                else
                                {
                                    this.Example_PB[i].Location = new System.Drawing.Point(50 + ((i - 2) * 150), 130);
                                    this.Example_RB[randnum, i].Location = new System.Drawing.Point(30 + ((i - 2) * 150), 170);
                                }
                                example_rand[i] = Generate_RandomNumber(example_rand, i, 4);
                                example_rand_num = example_rand[i];
                                this.Example_PB[i].ImageLocation = Question[randnum, example_rand_num + 1]; //그림 위치
                            }
                            else    //4와 같거나 클 때
                            {
                                if (i == 4)
                                {
                                    this.Example_RB[randnum, i].Visible = false;    //정답 숨김
                                    this.Example_PB[i].Visible = false;    //정답 숨김
                                }
                                this.Example_PB[i].ImageLocation = Question[randnum, i + 1]; //그림 위치
                            }
                        }
                        break;
                    case "IT":
                        Quiz_PB = new PictureBox();
                        this.Quiz_PB.Location = new System.Drawing.Point(30, 30);
                        this.Quiz_PB.Size = new System.Drawing.Size(100, 100);
                        this.Quiz_PB.ImageLocation = "Images/IU.jpg";        //임시 그림 위치
                        this.Quiz_PB.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
                        this.GB[n].Controls.Add(this.Quiz_PB);
                        for (int i = 0; i < 5; i++)
                        {
                            Example_RB[randnum, i] = new RadioButton();
                            this.Example_RB[randnum, i].Location = new System.Drawing.Point(140, 30 + (i * 30));
                            this.Example_RB[randnum, i].Size = new System.Drawing.Size(60, 15);
                            this.Controls.Add(Example_RB[randnum, i]);
                            this.GB[n].Controls.Add(this.Example_RB[randnum, i]);

                            if (i < 4)
                            {
                                example_rand[i] = Generate_RandomNumber(example_rand, i, 4);
                                example_rand_num = example_rand[i];
                                this.Example_RB[randnum, i].Text = Question[randnum, example_rand_num + 1];
                            }
                            else
                            {
                                this.Example_RB[randnum, i].Text = Question[randnum, i + 1];
                                this.Example_RB[randnum, i].Visible = false;    //정답 숨김
                            }
                        }
                        break;
                }
            }
            #endregion
        }
        #region  //채점하기
        void button_Click(object sender, EventArgs e)
        {
            int randnum;
            score = 0;
            for (int i = 0; i < 3; i++)
            {
                randnum = quiz_rand[i];
                switch (Question[randnum, 6])
                {
                    case "TT":
                    case "IT":
                        for (int j = 0; j < 4; j++)
                            if (Example_RB[randnum, j].Checked == true && (Example_RB[randnum, j].Text == Example_RB[randnum, 4].Text)) score++;
                        break;
                    case "TI":
                        for (int j = 0; j < 4; j++)
                            if (Example_RB[randnum, j].Checked == true && (Example_PB[j].ImageLocation == Example_PB[4].ImageLocation)) score++;
                        break;
                }
            }
            lbScore.Text = "score : " + Convert.ToString(score);
        }
        #endregion

        #region//난수생성( 랜덤문제 만드는 중요한 메소드)
        public int Generate_RandomNumber(int[] arr, int index, int size)
        {
            int i = 0;
            arr[index] = rand.Next(size);
            while (i <= size - 1)
            {
                if (i != index && arr[index] == arr[i])
                {
                    arr[index] = rand.Next(size);
                    i = 0;
                }
                else
                    i++;
            }
            return arr[index];
        }
        #endregion

        #region//문제유형 체크 후 놓아야할 Y 좌표 생성 후 반환
        public int ProblemTypeAndHeight(string[,] arr, int[] rand, int index)
        {
            if (arr[rand[index], 6] == "TT")
            {
                return 70 + GB[index].Location.Y;
            }
            else if (arr[rand[index], 6] == "IT")
            {
                return 200 + GB[index].Location.Y;
            }
            else if (arr[rand[index], 6] == "TI")
            {
                return 270 + GB[index].Location.Y;
            }
            else
                return -1;
        }
        #endregion
    }
}