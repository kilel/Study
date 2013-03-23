using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AVSlab
{
    public partial class Form1 : Form
    {
        private ImageWriter iw;
        private int current;
        public Form1()
        {
            InitializeComponent();

            iw = new ImageWriter(pic, "controller_"+comboBox.Text);
            current = 0;
        }

        private void bStart_Click(object sender, EventArgs e)
        {
            try
            {
                iw = new ImageWriter(pic, "controller_" + comboBox.Text);
            }
            catch (Exception exc)
            {
                MessageBox.Show("Такой команды нет", "Ошибка");
                return;
            }
            current = 0;
            timer.Start();
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            if (printStep());
            else
                timer.Stop();
        }
        bool printStep()
        {
            if (current < iw.length)
            {
                pic.Image = iw.print(current);
                ++current;
                return true;
            }
            return false;
        }
        private void nextStep_Click(object sender, EventArgs e)
        {
            printStep();
        }

        private void Claer_Click(object sender, EventArgs e)
        {
            current = 0;
            printStep();
        }
    }
}
