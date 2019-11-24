using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _201601639_자유낙하게임
{
    public partial class Form1 : Form
    {
        private Random rd = new Random((int)DateTime.Now.Ticks);
        private Point p_black;
        private Point p_yellow;
        private Point p_red;
        private Point p_blue;
        private bool diagonal_yellow = false;
        private bool diagonal_red = true;
        private bool diagonal_blue = false;
        //diagonal = true <-오른쪽 대각선으로, false면 왼쪽 대각선으로 움직임
        private int score = 0;
        public Form1()
        {
            InitializeComponent();
            p_black.X = 150; p_black.Y = 380;
            p_yellow.X = rd.Next(300); p_yellow.Y = rd.Next(300);
            p_red.X = rd.Next(300); p_red.Y = rd.Next(300);
            p_blue.X = rd.Next(300); p_blue.Y = rd.Next(300);

            Timer.Start();
        }
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            e.Graphics.FillEllipse(Brushes.Black, p_black.X, p_black.Y, 40, 40);
            e.Graphics.FillEllipse(Brushes.Red, p_red.X, p_red.Y, 40, 40);
            e.Graphics.FillEllipse(Brushes.Blue, p_blue.X, p_blue.Y, 40, 40);
            e.Graphics.FillEllipse(Brushes.Yellow, p_yellow.X, p_yellow.Y, 40, 40);
        }
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            
            switch (e.KeyCode)
            {
                case Keys.Left: p_black.X -= 20; if (p_black.X <= -30) p_black.X = 280; Invalidate(); break;
                case Keys.Right: p_black.X += 20; if (p_black.X >= 280) p_black.X = -30; Invalidate(); break;
                //case Keys.Up: p_black.Y -= 20; if (p_black.Y <= -50) p_black.Y = 500; Invalidate(); break;
                //case Keys.Down: p_black.Y += 20; if (p_black.Y >= 500) p_black.Y = -40; Invalidate(); break;
                default:
                    break;
            }
        }
        private bool isTouched(Point user, Point com)
        {
            double length = Math.Sqrt(Math.Pow(user.X - com.X, 2) + Math.Pow(user.Y - com.Y, 2));
            if (length <= 40)
                return true;
            else
                return false;
        }
        public Point Move_and_Difficulty(Point user, Point com, ref bool diagonal)
        {
            if (com.Y >= 380 || isTouched(user, com)) //바닥에 떨어졌거나 유저의 동그라미랑 컴퓨터의 동그라미가 맞붙었을 때
            {
                if (isTouched(user, com))//유저의 동그라미랑 컴퓨터의 동그라미가 맞붙었을 때
                {
                    score++;    //점수 증가
                    Timer.Interval -= 20;   //낙하속도 빨라짐
                }
                com.X = rd.Next(270);
                com.Y = rd.Next(270);
            }
            else        //도중에 낙하하는 경우
            {
                if (score >= 3)     //점수가 3점 이상일 때
                {
                    if (com.X >= 280 || !diagonal)  //만약에 오른쪽 벽에 부딪혔을 경우
                    {
                        com.X -= 10;    //왼쪽으로 이동
                        if (com.X <= 0)
                            diagonal = !diagonal;   //왼쪽 벽에 부딪혔을 경우 오른쪽으로 옮기게끔 값 바꿈
                    }
                    else if (com.X <= -20 || diagonal)  //왼쪽 벽에 부딪혔을 경우
                    {
                        com.X += 10;    //오른쪽으로 이동
                        if (com.X >= 280)
                            diagonal = !diagonal;       //오른쪽 벽에 부딪혔을 경우 왼쪽으로 옮기게끔 값 바꿈
                    }
                    com.Y += 10;
                }
                else
                    com.Y += 10;
            }
            return com;
        }
        private void Timer1_Tick(object sender, EventArgs e)
        {
            p_yellow = Move_and_Difficulty(p_black, p_yellow, ref diagonal_yellow);

            p_red = Move_and_Difficulty(p_black, p_red, ref diagonal_red);

            p_blue = Move_and_Difficulty(p_black, p_blue, ref diagonal_blue);

            Invalidate();
            
            lb_Result.Text = "현재 점수상태 : " + score + "점";
            if (score == 5)
            {
                Timer.Stop();
                MessageBox.Show("게임종료");
                Application.Exit();
            }
        }
    }
}
