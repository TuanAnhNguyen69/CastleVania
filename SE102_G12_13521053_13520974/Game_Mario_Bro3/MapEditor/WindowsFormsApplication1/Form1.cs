using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {

            InitializeComponent();
            listTile = new List<Bitmap>();
            listobjmap = new List<ObjectGame>();
            listobj = new List<ObjectGame>();
        }

        ObjectGame curObj;
        List<Bitmap> listTile;
        int[,] matTile;
        int countCol, countRow;
        Bitmap curTile;
        int mousePicMapX;
        int mousePicMapY;
        public static Rectangle viewPort;
        public static List<ObjectGame> listobj;
        public static List<ObjectGame> listobjmap;
        public static int scrHeight;
        Bitmap bmObjectInMap;
        QuadNode rootNode;
        private void button1_Click(object sender, EventArgs e) //load map
        {
            openFileDialog1.ShowDialog();
            try
            {
                pictureBox1.BackgroundImage = Bitmap.FromFile(openFileDialog1.FileName);
                pictureBox1.Width = pictureBox1.BackgroundImage.Width;
                pictureBox1.Height = pictureBox1.BackgroundImage.Height;
                countCol = pictureBox1.Width / 16;
                countRow = pictureBox1.Height / 16;
                pictureBox1.Image = new Bitmap(pictureBox1.Width, pictureBox1.Height);
                DrawDash();
                Cut();
            }
            catch
            {

            }
        }

        void DrawDash() //ve luoi
        {
            Graphics g = Graphics.FromImage(pictureBox1.Image);
            float[] dashValue = { 5, 2 };

            matTile = new int[countRow, countCol];
            Pen p= new Pen(Color.Silver);
            p.DashPattern = dashValue;
            for(int i = 0; i < countCol ; i++)
            {
                g.DrawLine(p, new Point(i * 16, 0), new Point(i*16,pictureBox1.Height));
            }

            for (int i = 0; i < countRow; i++)
            {
                g.DrawLine(p, new Point(0, i * 16), new Point(pictureBox1.Width,i * 16));
            }
        }

        public bool Compare(Bitmap bmp1, Bitmap bmp2)
        {
            if (bmp1 == null || bmp2 == null)
                return false;
            if (object.Equals(bmp1, bmp2))
                return true;
            if (!bmp1.Size.Equals(bmp2.Size) || !bmp1.PixelFormat.Equals(bmp2.PixelFormat))
                return false;

            int bytes = bmp1.Width * bmp1.Height * (Image.GetPixelFormatSize(bmp1.PixelFormat) / 8);

            bool result = true;
            byte[] b1bytes = new byte[bytes];
            byte[] b2bytes = new byte[bytes];

            BitmapData bitmapData1 = bmp1.LockBits(new Rectangle(0, 0, bmp1.Width - 1, bmp1.Height - 1), ImageLockMode.ReadOnly, bmp1.PixelFormat);
            BitmapData bitmapData2 = bmp2.LockBits(new Rectangle(0, 0, bmp2.Width - 1, bmp2.Height - 1), ImageLockMode.ReadOnly, bmp2.PixelFormat);

            Marshal.Copy(bitmapData1.Scan0, b1bytes, 0, bytes);
            Marshal.Copy(bitmapData2.Scan0, b2bytes, 0, bytes);

            for (int n = 0; n <= bytes - 1; n++)
            {
                if (b1bytes[n] != b2bytes[n])
                {
                    result = false;
                    break;
                }
            }

            bmp1.UnlockBits(bitmapData1);
            bmp2.UnlockBits(bitmapData2);

            return result;
        } //so sanh

        void DrawImage(Image bmDrawTo, Image bmDraw, Point pos, Rectangle rectClip) //ve
        {
            Graphics.FromImage(bmDrawTo).DrawImage(bmDraw, new Rectangle(pos.X, pos.Y, rectClip.Width, rectClip.Height), rectClip, GraphicsUnit.Pixel);
        }

        void Cut() //get tile
        {
             //int a = 0;
           for(int i =0; i <countRow; i++)
           {
               for(int j=0; j<countCol; j++)
               {
                   Bitmap b = new Bitmap(16, 16);
                   DrawImage(b, pictureBox1.BackgroundImage, new Point(0,0),new Rectangle(j*16,i*16,16,16));
                   bool allowAdd = true;
                   foreach (Bitmap bm in listTile)
                   {
                       if(Compare(b,bm))
                       {
                           allowAdd = false;
                           matTile[i, j] = (int)bm.Tag;
                       }
                   }

                   if(allowAdd)
                   {
                       b.Tag = listTile.Count;
                       listTile.Add(b);
                       matTile[i, j] = (int)b.Tag;
                       
                   }

               }
           }


           pictureBox2.Width = 16 * listTile.Count;
           pictureBox2.Height = 16;
           pictureBox2.BackgroundImage = new Bitmap(pictureBox2.Width, pictureBox2.Height);
           

            for (int i = 0; i<listTile.Count;i++)
            {
                DrawImage(pictureBox2.BackgroundImage, listTile[i], new Point(i * 16, 0), new Rectangle(0, 0, 16, 16));
            }
        }

        private void pictureBox2_MouseDown(object sender, MouseEventArgs e) //tao vien vuong luc chon tile
        {
            if(e.Y>16)
            { 
                return;
            }

            pictureBox2.Image = new Bitmap(pictureBox2.Width, pictureBox2.Height);
            Graphics g = Graphics.FromImage(pictureBox2.Image);
            g.DrawRectangle(new Pen(Color.Tomato),new Rectangle( (e.X / 16) * 16, 0, 16, 16));
            curTile = listTile[e.X / 16];
        }

        private void pictureBox2_Paint(object sender, PaintEventArgs e)
        {
            //no
        }

        
        void addObject() //them obj 
        {

            AddObject f = new AddObject();

            foreach(ObjectGame o in listobj)
            {
                f.comboBox1.Items.Add(o.ID);
            }
            f.comboBox1.Text = listobj.Count.ToString();
            f.ShowDialog();
            curObj = new ObjectGame(curTile, int.Parse(f.comboBox1.Text), f.cbType.Text);
            listobj.Add(curObj);
           
        }
        private void button2_Click(object sender, EventArgs e) //them obj vao list obj map
        {
            addObject();
            for (int i = 0; i < countRow; i++)
            {
                for (int j = 0; j < countCol; j++)
                {
                    if(matTile[i,j].Equals(curTile.Tag))
                    {
                        //Graphics.FromImage(pictureBox1.BackgroundImage).FillRectangle(Brushes.Black, new Rectangle(j * 16, i * 16, 16, 16));
                        ObjectGame obj = new ObjectGame(curTile, curObj.ID, curObj.objectType.ToString());
                        obj.SetLocation(j * 16, i * 16);
                        listobjmap.Add(obj);
                        pictureBox1.Invalidate();
                        
                    }
                }
            }            
        }

        private void button3_Click(object sender, EventArgs e) //luu file
        {
            String s="";
            SaveFileDialog sv = new SaveFileDialog();
          
            sv.ShowDialog();
  
            StreamWriter writer = new StreamWriter(sv.FileName);
           
            s += listobjmap.Count + "\r\n" + "\r\n";

            foreach(ObjectGame obj in listobjmap)
            {
                s += obj.ID + "\r\n";

                if(obj.ID == 11) //unknow
                {
                    int i = 0;

                    foreach(ObjectGame o in listobjmap)
                    {
                        if(o.location.X == obj.location.X && o.location.Y == obj.location.Y - 16)
                        {
                            s += i + "\r\n";
                        }
                        i++;
                    }
                }

                if(obj.ID == 10) // brick
                {
                    int i = 0;
                    foreach(ObjectGame o in listobjmap)
                    {
                        if (o.ID == 10)
                        {
                            s += "0" + "\r\n";
                        }
                        if (o.ID != 10 && o.location.X == obj.location.X && o.location.Y == obj.location.Y - 16)
                        {
                            s += i + "\r\n";
                        }
                        i++;
                    }
                }

                //if (obj.ID == 18) //down pipe
                //{
                //    int i = 0; 
                //    foreach (ObjectGame o in listobjmap)
                //    {
                //        if(o.ID ==19)
                //        {
                //            s += i + "\r\n";
                //        }
                //        i++;
                //    }
                //}

                //if (obj.ID == 20) // up pipe
                //{
                //    int i = 0;
                //    foreach (ObjectGame o in listobjmap)
                //    {
                //        if (o.ID == 21)
                //        {
                //            s += i + "\r\n";
                //        }
                //        i++;
                //    }
                //}

                s += obj.location.X + "\r\n";
                s += obj.location.Y + "\r\n";
                s += obj.bm.Width + "\r\n";
                s += obj.bm.Height + "\r\n";
                s += "\r\n";
            }
            writer.Write(s);
            writer.Close();

            StreamWriter quadtree = new StreamWriter(sv.FileName+"Quadtree");
            rootNode = new QuadNode("0", new Rectangle(0, 0, pictureBox1.Width, pictureBox1.Height));
            int ind = 0;
            foreach(ObjectGame obj in listobjmap)
            {
                obj.index = ind;
                ind++;
            }
            rootNode.listObj = listobjmap;
            rootNode.BuildTree();
            //foreach (ObjectGame o in listobjmap)
            //{
            //    rootNode.Insert(o);
            //}
            rootNode.Save(quadtree);
            quadtree.Close();
            MessageBox.Show("Saved");
        }
 
        private void button4_Click(object sender, EventArgs e) //them obj moi vao map
        {
            openFolder.ShowDialog();
            try
            {
                String[] listImg = Directory.GetFiles(openFolder.SelectedPath);
                foreach (String img in listImg)
                {
                    int id = int.Parse(getName(img));
                    Bitmap bm = (Bitmap)Bitmap.FromFile(img);
                    ObjectGame obj = new ObjectGame(bm, id, "Enemy");
                    //listobjmap.Add(obj);
                    listobj.Add(obj);
                    if (listobj.Count == 1)
                    {
                        pictureBox3.Width = 16;
                        pictureBox3.BackgroundImage = new Bitmap(pictureBox3.Width, pictureBox3.Height);
                        Graphics.FromImage(pictureBox3.BackgroundImage).Clear(Color.DarkGray);
                        DrawImage(pictureBox3.BackgroundImage, obj.bm, new Point((16 - obj.bm.Width), (pictureBox3.Height - obj.bm.Height)), new Rectangle(0, 0, 16, obj.bm.Height));
                        pictureBox3.BackgroundImage = obj.bm;
                    }
                    else
                    {
                        Bitmap bm1 = (Bitmap)pictureBox3.BackgroundImage;
                        pictureBox3.Width += 16;
                        pictureBox3.BackgroundImage = new Bitmap(pictureBox3.Width, pictureBox3.Height);
                        Graphics.FromImage(pictureBox3.BackgroundImage).Clear(Color.DarkGray);
                        DrawImage(pictureBox3.BackgroundImage, bm1, Point.Empty, new Rectangle(0, 0, bm1.Width, bm1.Height));
                        DrawImage(pictureBox3.BackgroundImage, obj.bm, new Point(bm1.Width + (16 - obj.bm.Width), (bm1.Height - obj.bm.Height)), new Rectangle(0, 0, obj.bm.Width, obj.bm.Height));
                    }
                }
            }
            catch
            { }
        }

     
        String getName(String path)
        {
            path = path.Remove(path.LastIndexOf('.'));
            String[] l = path.Split('\\');

            return l[l.Count() - 1];
        }
        private void label1_Click(object sender, EventArgs e)
        {
        }

        private void pictureBox3_MouseDown(object sender, MouseEventArgs e)
        {
           //no
        }

        private void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            int x, y, w, h;
            x = mousePicMapX;
            y = mousePicMapY;
            w = 16;
            h = 20;

            if(curObj!=null)
            {
                e.Graphics.DrawImage(curObj.bm, new Rectangle(x, y, curObj.bm.Width, curObj.bm.Height), new Rectangle(0, 0, curObj.bm.Width, curObj.bm.Height), GraphicsUnit.Pixel);

                e.Graphics.DrawRectangle(Pens.Red, new Rectangle(x, y, w, h));

                e.Graphics.DrawString(String.Format("({0};{1})", x + curObj.bm.Width / 2, pictureBox1.Height - y - curObj.bm.Height / 2), Font, Brushes.Black, new Point(x + curObj.bm.Width + 10, y));
            }
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            mousePicMapX = e.X;
            mousePicMapY = e.Y;
            pictureBox1.Invalidate();
        }

        private void pictureBox3_MouseDown_1(object sender, MouseEventArgs e)
        {
            pictureBox3.Image = new Bitmap(pictureBox3.BackgroundImage.Width, pictureBox3.BackgroundImage.Height);

            int i = e.X / 16;
            Graphics.FromImage(pictureBox3.Image).DrawRectangle(Pens.Red, new Rectangle(i * 16, 0, 16, 16));
            foreach (ObjectGame obj in listobj)
            {
                if (obj.ID == i)
                {
                    curObj = obj;
                    Graphics.FromImage(pictureBox3.Image).DrawRectangle(Pens.Red, new Rectangle(i * 16, 0, 16, obj.bm.Height));
                    pictureBox3.Invalidate();
                    return;
                }
            }
        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
        {

        }

        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                if(curObj!=null)
                {
                    int tilewidth = 16;
                    int tileheight = 16;
                    int x = (mousePicMapX / tilewidth) * tilewidth;
                    int y;
                    if(curObj.bm.Height % tileheight == 0)
                    {
                        y = (mousePicMapY / tileheight) * tileheight;
                    }
                    else
                    {
                        y = (mousePicMapY / tileheight) * tileheight + (tileheight - curObj.bm.Height % tileheight);
                    }
                    Point p = new Point(x, y);
                    DrawImage(pictureBox1.Image, curObj.bm, p, new Rectangle(0, 0, curObj.bm.Width, curObj.bm.Height));
                    ObjectGame obj = new ObjectGame(curObj.bm, curObj.ID, "Enemy");
                    obj.SetLocation(p.X, p.Y);
                    listobjmap.Add(obj);
                    curObj = obj;
                }
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {

        }
    }
}
