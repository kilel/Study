using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace lab3_tr
{
    public partial class Form1 : Form
    {
        private int n, m;
        public Form1()
        {
            InitializeComponent();
            n = m = 0;
            set_RC();
        }
        void set_RC()
        { 
            while (m < M.Value)
            {
                m++;
                cust.Columns.Add("cu" + m, "c" + m);
                cust.Columns[m - 1].Width = 50;
                we.Columns.Add("we" + m, "w" + m);
                we.Columns[m - 1].Width = 50;
            }
            while (m > M.Value)
            {
                m--;
                cust.Columns.RemoveAt(m);
                we.Columns.RemoveAt(m);
            }
            while (n < N.Value)
            {
                n++;
                if (sell.ColumnCount == 0)
                {
                    sell.Columns.Add("se", "se");
                    sell.Columns[0].Width = 55;
                }
                sell.Rows.Add();
                we.Rows.Add();
            }
            if (m > 0 && cust.RowCount == 0)
                cust.Rows.Add();
            while (n > N.Value)
            {
                n--;
                sell.Rows.RemoveAt(n);
                we.Rows.RemoveAt(n);
            }
        }


        private void N_ValueChanged(object sender, EventArgs e)
        {
            set_RC();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            List<int> s = new List<int>();
            List<int> c = new List<int>();
            List<List<int>> w = new List<List<int>>(n);
            
            for (int i = 0; i < n; i++)
                s.Add ( Convert.ToInt32(sell[0,i].Value.ToString())) ;
            for (int i = 0; i < m; i++)
                c.Add( Convert.ToInt32(cust[i, 0].Value.ToString()));
            for (int i = 0; i < n; i++)
            {
                w.Add(new List<int>());
                for (int j = 0; j < m; j++)
                    w[i].Add(Convert.ToInt32(we[j, i].Value.ToString()));
            }
            trans t = new trans(s,c,w);
            int meth = 0;
            if (radioButton1.Checked)
                meth = 1;
            else meth = 2;
            richTextBox1.Text = t.solve(meth); 
            
        }
    }
}
