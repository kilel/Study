using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace lab1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: данная строка кода позволяет загрузить данные в таблицу "adventureWorks2008R2DataSet.PersonPhone". При необходимости она может быть перемещена или удалена.
            this.personPhoneTableAdapter.Fill(this.adventureWorks2008R2DataSet.PersonPhone);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "adventureWorks2008R2DataSet.Person". При необходимости она может быть перемещена или удалена.
            this.personTableAdapter.Fill(this.adventureWorks2008R2DataSet.Person);
            // TODO: данная строка кода позволяет загрузить данные в таблицу "msdbDataSet.table_ololo". При необходимости она может быть перемещена или удалена.
            this.table_ololoTableAdapter.Fill(this.msdbDataSet.table_ololo);

        }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            try
            {
                this.Validate();
                this.tableololoBindingSource.EndEdit();
                this.table_ololoTableAdapter.Update(msdbDataSet);
                personBindingSource.EndEdit();
                personTableAdapter.Update(adventureWorks2008R2DataSet);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Не шали, малыш..");
                personTableAdapter.Dispose();
                personTableAdapter.Fill(adventureWorks2008R2DataSet.Person);
            }

        }
    }
}
