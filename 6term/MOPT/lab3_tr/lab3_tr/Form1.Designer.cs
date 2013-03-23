namespace lab3_tr
{
    partial class Form1
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.we = new System.Windows.Forms.DataGridView();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.M = new System.Windows.Forms.NumericUpDown();
            this.N = new System.Windows.Forms.NumericUpDown();
            this.sell = new System.Windows.Forms.DataGridView();
            this.cust = new System.Windows.Forms.DataGridView();
            this.button1 = new System.Windows.Forms.Button();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            ((System.ComponentModel.ISupportInitialize)(this.we)).BeginInit();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.M)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.N)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.sell)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cust)).BeginInit();
            this.SuspendLayout();
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(0, 0);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.ReadOnly = true;
            this.richTextBox1.Size = new System.Drawing.Size(378, 341);
            this.richTextBox1.TabIndex = 10;
            this.richTextBox1.Text = "";
            // 
            // we
            // 
            this.we.AllowUserToAddRows = false;
            this.we.AllowUserToDeleteRows = false;
            this.we.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.we.Location = new System.Drawing.Point(74, 75);
            this.we.Name = "we";
            this.we.RowHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.None;
            this.we.RowHeadersVisible = false;
            this.we.ShowEditingIcon = false;
            this.we.Size = new System.Drawing.Size(260, 189);
            this.we.TabIndex = 4;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.M);
            this.groupBox1.Controls.Add(this.N);
            this.groupBox1.Controls.Add(this.sell);
            this.groupBox1.Controls.Add(this.cust);
            this.groupBox1.Controls.Add(this.we);
            this.groupBox1.Location = new System.Drawing.Point(384, 12);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(340, 270);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Данные";
            // 
            // M
            // 
            this.M.Location = new System.Drawing.Point(6, 19);
            this.M.Name = "M";
            this.M.Size = new System.Drawing.Size(62, 20);
            this.M.TabIndex = 4;
            this.M.TabStop = false;
            this.M.Value = new decimal(new int[] {
            3,
            0,
            0,
            0});
            this.M.ValueChanged += new System.EventHandler(this.N_ValueChanged);
            // 
            // N
            // 
            this.N.Location = new System.Drawing.Point(6, 49);
            this.N.Name = "N";
            this.N.Size = new System.Drawing.Size(62, 20);
            this.N.TabIndex = 4;
            this.N.TabStop = false;
            this.N.Value = new decimal(new int[] {
            3,
            0,
            0,
            0});
            this.N.ValueChanged += new System.EventHandler(this.N_ValueChanged);
            // 
            // sell
            // 
            this.sell.AllowUserToAddRows = false;
            this.sell.AllowUserToDeleteRows = false;
            this.sell.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.sell.Location = new System.Drawing.Point(6, 75);
            this.sell.Name = "sell";
            this.sell.RowHeadersVisible = false;
            this.sell.Size = new System.Drawing.Size(62, 189);
            this.sell.TabIndex = 3;
            // 
            // cust
            // 
            this.cust.AllowUserToAddRows = false;
            this.cust.AllowUserToDeleteRows = false;
            this.cust.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.cust.Location = new System.Drawing.Point(74, 19);
            this.cust.Name = "cust";
            this.cust.RowHeadersBorderStyle = System.Windows.Forms.DataGridViewHeaderBorderStyle.None;
            this.cust.RowHeadersVisible = false;
            this.cust.Size = new System.Drawing.Size(260, 50);
            this.cust.TabIndex = 2;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(458, 288);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(266, 41);
            this.button1.TabIndex = 3;
            this.button1.Text = "Решить";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Checked = true;
            this.radioButton1.Location = new System.Drawing.Point(384, 288);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(60, 17);
            this.radioButton1.TabIndex = 11;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "N-W_A";
            this.radioButton1.UseVisualStyleBackColor = true;
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(384, 311);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(58, 17);
            this.radioButton2.TabIndex = 11;
            this.radioButton2.TabStop = true;
            this.radioButton2.Text = "MIN_T";
            this.radioButton2.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Info;
            this.ClientSize = new System.Drawing.Size(736, 341);
            this.Controls.Add(this.radioButton2);
            this.Controls.Add(this.radioButton1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.richTextBox1);
            this.Name = "Form1";
            this.ShowIcon = false;
            this.Text = "tr_solve";
            ((System.ComponentModel.ISupportInitialize)(this.we)).EndInit();
            this.groupBox1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.M)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.N)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.sell)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cust)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.DataGridView we;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.NumericUpDown M;
        private System.Windows.Forms.NumericUpDown N;
        private System.Windows.Forms.DataGridView sell;
        private System.Windows.Forms.DataGridView cust;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.RadioButton radioButton2;
    }
}

