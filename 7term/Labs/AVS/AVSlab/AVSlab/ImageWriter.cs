using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms; 
using System.IO;
using System.Drawing;

namespace AVSlab
{
    class ImageWriter
    {
        Bitmap image;
        Graphics g;
        private string[] commands; 
        public int length;
        private List<Point> points;
        private List<int> getIntArray(String s){
            List<int> li = new List<int>();
            string[] ls = s.Split(' ');
            foreach (string ss in ls){
                if (ss[0] == '/')
                    break;
                li.Add(int.Parse(ss));
            }
            return li;
        }

        public ImageWriter(PictureBox pic, string controller){
            this.image = new Bitmap( pic.Width, pic.Height);
            g = Graphics.FromImage(image);

            try
            {
                commands = File.ReadAllLines(controller);
            }
            catch (Exception e)
            {
                throw new Exception("Такой команды нет!");
            }
            length = commands.Length;

            //System.IO.BinaryReader br = new BinaryReader(File.OpenRead("points"));
            StreamReader sr = new StreamReader("points");

            int n = int.Parse( sr.ReadLine());
            points = new List<Point>(n);
            for (int i = 0; i < n; ++i)
            {
                List<int> arg = getIntArray(sr.ReadLine());
                points.Add(new Point(arg[0], arg[1]));
            }
            sr.Close();
        }
        public Image print(int i)
        {
            List<int> com = getIntArray(commands[i]);
            Color c = new Color();
            g.Clear(new Color());
            foreach (int f in com)
            {
                g.FillEllipse(Brushes.Red, points[f].X - 5, points[f].Y - 5, 10, 10);
            }
            return image;
        }
    }
}
