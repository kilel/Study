namespace AVSlab
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.pic = new System.Windows.Forms.PictureBox();
            this.bStart = new System.Windows.Forms.Button();
            this.timer = new System.Windows.Forms.Timer(this.components);
            this.nextStep = new System.Windows.Forms.Button();
            this.Claer = new System.Windows.Forms.Button();
            this.comboBox = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.pic)).BeginInit();
            this.SuspendLayout();
            // 
            // pic
            // 
            this.pic.BackColor = System.Drawing.Color.White;
            this.pic.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("pic.BackgroundImage")));
            this.pic.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.pic.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pic.Location = new System.Drawing.Point(0, 0);
            this.pic.Name = "pic";
            this.pic.Size = new System.Drawing.Size(938, 420);
            this.pic.TabIndex = 0;
            this.pic.TabStop = false;
            // 
            // bStart
            // 
            this.bStart.Location = new System.Drawing.Point(12, 337);
            this.bStart.Name = "bStart";
            this.bStart.Size = new System.Drawing.Size(101, 33);
            this.bStart.TabIndex = 1;
            this.bStart.Text = "Начинаем";
            this.bStart.UseVisualStyleBackColor = true;
            this.bStart.Click += new System.EventHandler(this.bStart_Click);
            // 
            // timer
            // 
            this.timer.Interval = 300;
            this.timer.Tick += new System.EventHandler(this.timer_Tick);
            // 
            // nextStep
            // 
            this.nextStep.Location = new System.Drawing.Point(12, 376);
            this.nextStep.Name = "nextStep";
            this.nextStep.Size = new System.Drawing.Size(101, 33);
            this.nextStep.TabIndex = 1;
            this.nextStep.Text = "Шаг вперёд";
            this.nextStep.UseVisualStyleBackColor = true;
            this.nextStep.Click += new System.EventHandler(this.nextStep_Click);
            // 
            // Claer
            // 
            this.Claer.Location = new System.Drawing.Point(119, 376);
            this.Claer.Name = "Claer";
            this.Claer.Size = new System.Drawing.Size(101, 33);
            this.Claer.TabIndex = 1;
            this.Claer.Text = "Сброс";
            this.Claer.UseVisualStyleBackColor = true;
            this.Claer.Click += new System.EventHandler(this.Claer_Click);
            // 
            // comboBox
            // 
            this.comboBox.FormattingEnabled = true;
            this.comboBox.Items.AddRange(new object[] {
            "jmp",
            "add",
            "mov"});
            this.comboBox.Location = new System.Drawing.Point(120, 349);
            this.comboBox.Name = "comboBox";
            this.comboBox.Size = new System.Drawing.Size(100, 21);
            this.comboBox.TabIndex = 2;
            this.comboBox.Text = "jmp";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.ClientSize = new System.Drawing.Size(938, 420);
            this.Controls.Add(this.comboBox);
            this.Controls.Add(this.Claer);
            this.Controls.Add(this.nextStep);
            this.Controls.Add(this.bStart);
            this.Controls.Add(this.pic);
            this.Name = "Form1";
            this.Text = "h";
            ((System.ComponentModel.ISupportInitialize)(this.pic)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox pic;
        private System.Windows.Forms.Button bStart;
        private System.Windows.Forms.Timer timer;
        private System.Windows.Forms.Button nextStep;
        private System.Windows.Forms.Button Claer;
        private System.Windows.Forms.ComboBox comboBox;
    }
}

