namespace _201601639_주민과제
{
    partial class Form_Resident
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.lb_ResidentNumber = new System.Windows.Forms.Label();
            this.txt_FrontResidentNumber = new System.Windows.Forms.TextBox();
            this.txt_LastResidentNumber = new System.Windows.Forms.TextBox();
            this.lb_CenterBar = new System.Windows.Forms.Label();
            this.btn_Return = new System.Windows.Forms.Button();
            this.lb_Birth = new System.Windows.Forms.Label();
            this.lb_Sex = new System.Windows.Forms.Label();
            this.lb_Age = new System.Windows.Forms.Label();
            this.txt_Year = new System.Windows.Forms.TextBox();
            this.txt_Month = new System.Windows.Forms.TextBox();
            this.lb_Year = new System.Windows.Forms.Label();
            this.lb_Month = new System.Windows.Forms.Label();
            this.txt_Day = new System.Windows.Forms.TextBox();
            this.lb_Day = new System.Windows.Forms.Label();
            this.txt_Sex = new System.Windows.Forms.TextBox();
            this.txt_Age = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // lb_ResidentNumber
            // 
            this.lb_ResidentNumber.AutoSize = true;
            this.lb_ResidentNumber.Location = new System.Drawing.Point(12, 41);
            this.lb_ResidentNumber.Name = "lb_ResidentNumber";
            this.lb_ResidentNumber.Size = new System.Drawing.Size(81, 12);
            this.lb_ResidentNumber.TabIndex = 0;
            this.lb_ResidentNumber.Text = "주민번호 입력";
            // 
            // txt_FrontResidentNumber
            // 
            this.txt_FrontResidentNumber.Location = new System.Drawing.Point(116, 38);
            this.txt_FrontResidentNumber.Name = "txt_FrontResidentNumber";
            this.txt_FrontResidentNumber.Size = new System.Drawing.Size(100, 21);
            this.txt_FrontResidentNumber.TabIndex = 1;
            this.txt_FrontResidentNumber.Text = "앞 6자리";
            this.txt_FrontResidentNumber.MouseClick += new System.Windows.Forms.MouseEventHandler(this.txt_FrontResidentNumber_MouseClick);
            this.txt_FrontResidentNumber.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txt_FrontResidentNumber_KeyPress);
            // 
            // txt_LastResidentNumber
            // 
            this.txt_LastResidentNumber.Location = new System.Drawing.Point(239, 38);
            this.txt_LastResidentNumber.Name = "txt_LastResidentNumber";
            this.txt_LastResidentNumber.Size = new System.Drawing.Size(100, 21);
            this.txt_LastResidentNumber.TabIndex = 2;
            this.txt_LastResidentNumber.Text = "뒤 7자리";
            this.txt_LastResidentNumber.MouseClick += new System.Windows.Forms.MouseEventHandler(this.txt_LastResidentNumber_MouseClick);
            this.txt_LastResidentNumber.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txt_LastResidentNumber_KeyPress);
            // 
            // lb_CenterBar
            // 
            this.lb_CenterBar.AutoSize = true;
            this.lb_CenterBar.Location = new System.Drawing.Point(222, 41);
            this.lb_CenterBar.Name = "lb_CenterBar";
            this.lb_CenterBar.Size = new System.Drawing.Size(11, 12);
            this.lb_CenterBar.TabIndex = 3;
            this.lb_CenterBar.Text = "-";
            // 
            // btn_Return
            // 
            this.btn_Return.Location = new System.Drawing.Point(116, 78);
            this.btn_Return.Name = "btn_Return";
            this.btn_Return.Size = new System.Drawing.Size(75, 23);
            this.btn_Return.TabIndex = 4;
            this.btn_Return.Text = "확인";
            this.btn_Return.UseVisualStyleBackColor = true;
            this.btn_Return.Click += new System.EventHandler(this.btn_Return_Click);
            // 
            // lb_Birth
            // 
            this.lb_Birth.AutoSize = true;
            this.lb_Birth.Location = new System.Drawing.Point(12, 134);
            this.lb_Birth.Name = "lb_Birth";
            this.lb_Birth.Size = new System.Drawing.Size(53, 12);
            this.lb_Birth.TabIndex = 5;
            this.lb_Birth.Text = "생년월일";
            // 
            // lb_Sex
            // 
            this.lb_Sex.AutoSize = true;
            this.lb_Sex.Location = new System.Drawing.Point(12, 172);
            this.lb_Sex.Name = "lb_Sex";
            this.lb_Sex.Size = new System.Drawing.Size(29, 12);
            this.lb_Sex.TabIndex = 6;
            this.lb_Sex.Text = "성별";
            // 
            // lb_Age
            // 
            this.lb_Age.AutoSize = true;
            this.lb_Age.Location = new System.Drawing.Point(12, 213);
            this.lb_Age.Name = "lb_Age";
            this.lb_Age.Size = new System.Drawing.Size(29, 12);
            this.lb_Age.TabIndex = 7;
            this.lb_Age.Text = "나이";
            // 
            // txt_Year
            // 
            this.txt_Year.Location = new System.Drawing.Point(116, 131);
            this.txt_Year.Name = "txt_Year";
            this.txt_Year.Size = new System.Drawing.Size(44, 21);
            this.txt_Year.TabIndex = 8;
            // 
            // txt_Month
            // 
            this.txt_Month.Location = new System.Drawing.Point(189, 131);
            this.txt_Month.Name = "txt_Month";
            this.txt_Month.Size = new System.Drawing.Size(44, 21);
            this.txt_Month.TabIndex = 9;
            // 
            // lb_Year
            // 
            this.lb_Year.AutoSize = true;
            this.lb_Year.Location = new System.Drawing.Point(166, 134);
            this.lb_Year.Name = "lb_Year";
            this.lb_Year.Size = new System.Drawing.Size(17, 12);
            this.lb_Year.TabIndex = 10;
            this.lb_Year.Text = "년";
            // 
            // lb_Month
            // 
            this.lb_Month.AutoSize = true;
            this.lb_Month.Location = new System.Drawing.Point(239, 134);
            this.lb_Month.Name = "lb_Month";
            this.lb_Month.Size = new System.Drawing.Size(17, 12);
            this.lb_Month.TabIndex = 11;
            this.lb_Month.Text = "월";
            // 
            // txt_Day
            // 
            this.txt_Day.Location = new System.Drawing.Point(262, 131);
            this.txt_Day.Name = "txt_Day";
            this.txt_Day.Size = new System.Drawing.Size(44, 21);
            this.txt_Day.TabIndex = 12;
            // 
            // lb_Day
            // 
            this.lb_Day.AutoSize = true;
            this.lb_Day.Location = new System.Drawing.Point(312, 134);
            this.lb_Day.Name = "lb_Day";
            this.lb_Day.Size = new System.Drawing.Size(17, 12);
            this.lb_Day.TabIndex = 13;
            this.lb_Day.Text = "일";
            // 
            // txt_Sex
            // 
            this.txt_Sex.Location = new System.Drawing.Point(116, 169);
            this.txt_Sex.Name = "txt_Sex";
            this.txt_Sex.Size = new System.Drawing.Size(44, 21);
            this.txt_Sex.TabIndex = 14;
            // 
            // txt_Age
            // 
            this.txt_Age.Location = new System.Drawing.Point(116, 210);
            this.txt_Age.Name = "txt_Age";
            this.txt_Age.Size = new System.Drawing.Size(44, 21);
            this.txt_Age.TabIndex = 15;
            // 
            // Form_Resident
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(384, 261);
            this.Controls.Add(this.txt_Age);
            this.Controls.Add(this.txt_Sex);
            this.Controls.Add(this.lb_Day);
            this.Controls.Add(this.txt_Day);
            this.Controls.Add(this.lb_Month);
            this.Controls.Add(this.lb_Year);
            this.Controls.Add(this.txt_Month);
            this.Controls.Add(this.txt_Year);
            this.Controls.Add(this.lb_Age);
            this.Controls.Add(this.lb_Sex);
            this.Controls.Add(this.lb_Birth);
            this.Controls.Add(this.btn_Return);
            this.Controls.Add(this.lb_CenterBar);
            this.Controls.Add(this.txt_LastResidentNumber);
            this.Controls.Add(this.txt_FrontResidentNumber);
            this.Controls.Add(this.lb_ResidentNumber);
            this.Name = "Form_Resident";
            this.Text = "주민과제";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lb_ResidentNumber;
        private System.Windows.Forms.TextBox txt_FrontResidentNumber;
        private System.Windows.Forms.TextBox txt_LastResidentNumber;
        private System.Windows.Forms.Label lb_CenterBar;
        private System.Windows.Forms.Button btn_Return;
        private System.Windows.Forms.Label lb_Birth;
        private System.Windows.Forms.Label lb_Sex;
        private System.Windows.Forms.Label lb_Age;
        private System.Windows.Forms.TextBox txt_Year;
        private System.Windows.Forms.TextBox txt_Month;
        private System.Windows.Forms.Label lb_Year;
        private System.Windows.Forms.Label lb_Month;
        private System.Windows.Forms.TextBox txt_Day;
        private System.Windows.Forms.Label lb_Day;
        private System.Windows.Forms.TextBox txt_Sex;
        private System.Windows.Forms.TextBox txt_Age;
    }
}

