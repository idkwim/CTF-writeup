using System;
using System.ComponentModel;
using System.Drawing;
using System.IO;
using System.Text;
using System.Windows.Forms;

namespace POWEROFXX_easy_reversing
{
	public class Form1 : Form
	{
		public string StrangeString = "9pMaVs5DxiOPGe8JETXYmg3lbudro6Qk1WLKwyhfnS4Iv0ABtjUCc7RZz2NFHq";

		public int DayOfYear = DateTime.Today.DayOfYear;

		public int Hour = DateTime.Now.Hour;

		public int Minute = DateTime.Now.Minute;S

		public int Month = DateTime.Today.Month;

		public int Day = DateTime.Today.Day;

		private IContainer components;

		private Button button1;

		private Panel panel1;

		private Panel panel2;

		private Label label3;

		private TextBox textBox1;

		private TextBox textBox2;

		private Label label1;

		private void textbox1_mouseclick(object sender, MouseEventArgs e)
		{
		}

		public Form1()
		{
			this.InitializeComponent();
			this.StrangeString += "KfeROdEILJs5W6D1m4XFtH7YbwgrUConPuqQBcSxT092zljv8yMAGhpZN3akVi";
			this.StrangeString += "8vxekVPpYlsXDAujWoJEingTGf3mCh59LROt6cdUNMb41zH7Kr0yS2BIFZqawQ";
		}

		public string xorString(string a)
		{
			StringBuilder stringBuilder = new StringBuilder();
			int num = this.Month;			//10
			char[] array = a.ToCharArray();	//string a to char array
			for (int i = 0; i < a.Length; i++)
			{
				stringBuilder.Append((int)(this.StrangeString[i + num] ^ array[i]) + " ");	//StrangeString[i+10]^array[i]
			}
			return stringBuilder.ToString();
		}

		public int changeNum(string chr, int range)
		{
			int num = int.Parse(chr);	//num is char 
			int num2 = range % 3;
			int num3 = 2;
			if (num2 == 0)
			{
				num += this.Day * num3 + this.Minute * num3 - this.Hour * 2;	//num = num + 26 * 2 + 44 * 2 - 23 * 2
																				//num = num + 94
			}
			else if (num2 == 1)
			{
				num += this.Month * 3 + this.Minute * 2 - this.Hour * num2;		//num = num + 10 * 3 + 44 * 2 - 23 * 1
																				//num = num + 95
			}
			else if (num2 == 2)
			{
				//num = num + 299 - 10 * 10 - 44 * 2 - 23 * 6 - 4
				//num = num - 31
				num += this.DayOfYear - this.Month * (num2 * 5) - this.Minute * num2 - this.Hour * (num3 + 4) - num2 * num3;
			}
			return num;
		}

		public void lfkfidngigiwhiu3yr89igorg(string str)
		{
			string text = "Sweet Secret Memo _ lfkfidngigiwhiu3yr89igorg 0.1\r\n";
			object obj = text;
			text = string.Concat(new object[]
			{
				obj,
				"Date : ",
				this.Month,
				".",
				this.Day,
				"_",
				this.Hour,
				":",
				this.Minute,
				" [UTC + 09:00]\r\n"
			});
			text = text + "Your Message : " + str + "\r\n\r\n";
			text += "End of Log";
			StreamWriter streamWriter = new StreamWriter("savelog.txt");
			streamWriter.Write(text);
			streamWriter.Close();
		}

		public void gettime()
		{
			this.DayOfYear = DateTime.Today.DayOfYear;
			this.Minute = DateTime.Now.Minute;
			this.Month = DateTime.Today.Month;
			this.Day = DateTime.Today.Day;
			this.Hour = DateTime.Now.Hour;
		}

		public static string upsideDownInput(string input)
		{
			int length = input.Length;
			char[] array = new char[length];
			for (int i = 0; i < input.Length; i++)
			{
				array[i] = input[length - i - 1];
			}
			return new string(array);
		}

		private void Form1_Load(object sender, EventArgs e)
		{
			this.panel2.BackColor = Color.Transparent;
			this.StrangeString += "Hv8VzYa5b1FMGNODW4kwX9L3hK6SqsTtyxoE0Z7fPJIgrCAQiljBuenRcp2dUm";
			this.StrangeString += "fgnCw4HPJRdXKIq31YNDZMS82OjA7eUxpozasVmykiQrTFLW6htGb9B0lEcvu5";
			this.StrangeString += "jxLaZdWYngAfKGNhzTcXQU7Jy9sFbp0eRI1ECrv23PSw846oH5MBVtlDiOqumk";
			this.StrangeString += "U0tnl9bVK4iB2LzZXy7PaCHcAI5pOsSfjgqkr1vuRTFEo8Dxmhw3QGdeJM6WYN";
			this.StrangeString += "gWYN9w4LuPjxJl1MhOkniQy8CBUXr6THaKDctEdb0Imp32VfFZGvAS5ezqsR7o";
			this.StrangeString += "wj3J9fL8QY2kArXKgOEzmSdqHpcMsn1ahGWxCe7yPIlTuDRb6F40oZtiUBvV5N";
		}

		private void panel_doubleclick(object sender, MouseEventArgs e)
		{
			MessageBox.Show("aHR0cDovL2lsc3B5Lm5ldC8=", "__BASE64__");
		}

		public string encodeStart(string str)
		{
			StringBuilder stringBuilder = new StringBuilder();
			string text = this.xorString(Form1.upsideDownInput(str));
			string[] array = text.Split(new char[]
			{
				' '
			});
			for (int i = 0; i < array.Length - 1; i++)
			{
				stringBuilder.Append(this.changeNum(array[i], i) + " ");
			}
			return stringBuilder.ToString();
		}

		private void button1_Click(object sender, EventArgs e)
		{
			if (this.textBox2.Text.Length > this.StrangeString.Length - this.Month)
			{
				MessageBox.Show("Length Error", "ERROR_bb");
				return;
			}
			this.gettime();
			string text = this.encodeStart(this.textBox2.Text);
			this.textBox1.Text = text;
			this.lfkfidngigiwhiu3yr89igorg(text);
		}

		private void textBox2_MouseClick(object sender, MouseEventArgs e)
		{
			if (this.textBox2.Text == "Input Your Plain Text")
			{
				this.textBox2.Text = "";
			}
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && this.components != null)
			{
				this.components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(Form1));
			this.button1 = new Button();
			this.panel1 = new Panel();
			this.textBox2 = new TextBox();
			this.label3 = new Label();
			this.textBox1 = new TextBox();
			this.panel2 = new Panel();
			this.label1 = new Label();
			this.panel1.SuspendLayout();
			base.SuspendLayout();
			this.button1.BackColor = Color.CornflowerBlue;
			this.button1.FlatStyle = FlatStyle.Popup;
			this.button1.Font = new Font("맑은 고딕", 9f, FontStyle.Bold, GraphicsUnit.Point, 129);
			this.button1.ForeColor = Color.Black;
			this.button1.Location = new Point(508, 69);
			this.button1.Name = "button1";
			this.button1.Size = new Size(75, 23);
			this.button1.TabIndex = 10;
			this.button1.Text = "SUBM1T";
			this.button1.UseVisualStyleBackColor = false;
			this.button1.Click += new EventHandler(this.button1_Click);
			this.panel1.BackColor = SystemColors.ActiveCaptionText;
			this.panel1.Controls.Add(this.label1);
			this.panel1.Controls.Add(this.textBox2);
			this.panel1.Controls.Add(this.label3);
			this.panel1.Controls.Add(this.textBox1);
			this.panel1.Controls.Add(this.button1);
			this.panel1.Location = new Point(0, 269);
			this.panel1.Name = "panel1";
			this.panel1.Size = new Size(597, 99);
			this.panel1.TabIndex = 11;
			this.textBox2.BackColor = Color.Black;
			this.textBox2.BorderStyle = BorderStyle.FixedSingle;
			this.textBox2.Font = new Font("맑은 고딕", 9f, FontStyle.Bold, GraphicsUnit.Point, 129);
			this.textBox2.ForeColor = SystemColors.GradientActiveCaption;
			this.textBox2.Location = new Point(12, 25);
			this.textBox2.Name = "textBox2";
			this.textBox2.Size = new Size(491, 23);
			this.textBox2.TabIndex = 17;
			this.textBox2.Text = "Input Your Plain Text";
			this.textBox2.MouseClick += new MouseEventHandler(this.textBox2_MouseClick);
			this.label3.AutoSize = true;
			this.label3.Font = new Font("맑은 고딕", 9.75f, FontStyle.Regular, GraphicsUnit.Point, 129);
			this.label3.ForeColor = Color.FromArgb(192, 192, 255);
			this.label3.Location = new Point(9, 51);
			this.label3.Name = "label3";
			this.label3.Size = new Size(112, 17);
			this.label3.TabIndex = 16;
			this.label3.Text = "Crypted Message";
			this.textBox1.BackColor = Color.Black;
			this.textBox1.BorderStyle = BorderStyle.FixedSingle;
			this.textBox1.Font = new Font("맑은 고딕", 9f, FontStyle.Bold, GraphicsUnit.Point, 129);
			this.textBox1.ForeColor = SystemColors.GradientActiveCaption;
			this.textBox1.Location = new Point(12, 69);
			this.textBox1.Name = "textBox1";
			this.textBox1.Size = new Size(491, 23);
			this.textBox1.TabIndex = 15;
			this.textBox1.MouseClick += new MouseEventHandler(this.textbox1_mouseclick);
			this.panel2.Location = new Point(303, 12);
			this.panel2.Name = "panel2";
			this.panel2.Size = new Size(281, 140);
			this.panel2.TabIndex = 15;
			this.panel2.MouseDoubleClick += new MouseEventHandler(this.panel_doubleclick);
			this.label1.AutoSize = true;
			this.label1.Font = new Font("맑은 고딕", 9.75f, FontStyle.Regular, GraphicsUnit.Point, 129);
			this.label1.ForeColor = Color.FromArgb(192, 192, 255);
			this.label1.Location = new Point(9, 7);
			this.label1.Name = "label1";
			this.label1.Size = new Size(94, 17);
			this.label1.TabIndex = 18;
			this.label1.Text = "Plain Message";
			base.AutoScaleDimensions = new SizeF(7f, 12f);
			base.AutoScaleMode = AutoScaleMode.Font;
			this.BackColor = SystemColors.Control;
			this.BackgroundImage = (Image)componentResourceManager.GetObject("$this.BackgroundImage");
			base.ClientSize = new Size(596, 368);
			base.Controls.Add(this.panel2);
			base.Controls.Add(this.panel1);
			this.ForeColor = SystemColors.ControlText;
			base.FormBorderStyle = FormBorderStyle.FixedSingle;
			base.Icon = (Icon)componentResourceManager.GetObject("$this.Icon");
			base.MaximizeBox = false;
			base.MinimizeBox = false;
			base.Name = "Form1";
			this.Text = "2013 POWER OF XX - Easy Reverse Engineering 2";
			base.Load += new EventHandler(this.Form1_Load);
			this.panel1.ResumeLayout(false);
			this.panel1.PerformLayout();
			base.ResumeLayout(false);
		}
	}
}
