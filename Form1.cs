using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 光机电上位机控制系统
{
    public partial class Form1 : Form
    {
        public static Form1 form1;
        public Form1()
        {
            InitializeComponent();
            form1 = this;
            Task.Run(() => um.rushaxisdata(), um.cts.Token);
        }

        Form_System mFormSystem = new Form_System();
        Form_Config mForm_Config = new Form_Config();
        use_motion um = new use_motion();
        ManualResetEvent OnOffhoming = new ManualResetEvent(true);
        ManualResetEvent OnOffaotuwork = new ManualResetEvent(true);
        Thread thHome;
        Thread thAotu;
        private void Form1_Load(object sender, EventArgs e)
        {
            um.openBorad();
            um.readData();
            um.readSpeed();
            um.openCamera();
            timer_pos.Start();
            Control.CheckForIllegalCrossThreadCalls = false;
        }
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            um.closeCamera();
            um.cts.Cancel();
            timer_pos.Stop();
            LTDMC.dmc_write_sevon_pin(0, 0, 1);
            LTDMC.dmc_write_sevon_pin(0, 1, 1);
            LTDMC.dmc_board_close();//控制卡关闭函数，释放系统资源
        }
        private void openForm_System()
        {
            if (mFormSystem == null) mFormSystem = (Form_System)LoadMdiChild(typeof(Form_System));
            ShowMdiChild(mFormSystem);
        }
        private void openForm_Config()
        {
            if (mForm_Config == null) mForm_Config = (Form_Config)LoadMdiChild(typeof(Form_Config));
            ShowMdiChild(mForm_Config);
        }
        private Form LoadMdiChild(Type formClass)
        {
            Form nForm = null;
            foreach (Form frm in this.MdiChildren)
            {
                if (frm.GetType() == formClass)
                {
                    nForm = frm;
                    break;
                }
            }
            if (nForm == null)
            {
                nForm = (Form)(Activator.CreateInstance(formClass));
                nForm.Owner = this;
                nForm.Left = 0;
                nForm.Top = 0;
                nForm.Dock = System.Windows.Forms.DockStyle.Fill;
                nForm.FormBorderStyle = FormBorderStyle.None;
                nForm.MaximizeBox = false;
                nForm.MinimizeBox = false;
                nForm.ControlBox = false;
                nForm.TopLevel = false;
            }
            return nForm;
        }
        private void ShowMdiChild(Form frmObject)
        {
            if (this.ActiveMdiChild == frmObject) return;
            frmObject.TopLevel = false; //重要的一个步骤
            frmObject.Show();
            frmObject.BringToFront();
            frmObject.Activate();
            Mdi_panel.Controls.Clear();
            Mdi_panel.Controls.Add(frmObject);
            Mdi_panel.Tag = frmObject;
        }
        public void Dohomed()
        {
            while (true)
            {
                OnOffhoming.WaitOne();
                um.homeing();
                if (um.AxisState == AxisState.STANDBY)
                {
                    textBox_Xpos.Text = 0.ToString();
                    textBox_Ypos.Text = 0.ToString();
                    textBox_Zpos.Text = 0.ToString();
                    textBox_Rpos.Text = 0.ToString();
                    OnOffhoming.Reset();
                }
            }
        }
        private void toolStripButton_stop_Click(object sender, EventArgs e)
        {
            doStophome();
            doStopwork();
        }
        public void doStophome()
        {
            OnOffhoming.Reset();
            Thread.Sleep(100);
            um.stopAxis();
        }
        public void doStopwork()
        {
            OnOffaotuwork.Reset();
            Thread.Sleep(100);
            um.stopAxis();
        }
        private void toolStripButton_product_Click(object sender, EventArgs e)
        {
            openForm_Config();
        }
        private void toolStripButton_system_Click(object sender, EventArgs e)
        {
            openForm_System();
        }

        private void toolStripButton_home_Click(object sender, EventArgs e)
        {
            OnOffhoming.Set();
            thHome = new Thread(Dohomed);
            thHome.IsBackground = true;
            thHome.Start();
        }
        private void toolStripButton_start_Click(object sender, EventArgs e)
        {
            um.AxisState = AxisState.RUNNING;
            um.WorkState = WorkState.dostop;
            OnOffaotuwork.Set();
            thAotu = new Thread(doaotuWork);
            thAotu.IsBackground = true;
            thAotu.Start();
        }
        private void doaotuWork()
        {
            while (true)
            {
                OnOffaotuwork.WaitOne();
                um.doAotuWork(this, 0, 1, hWindowControl_getVision.HalconWindow, hWindowControl_chekVision.HalconWindow);
            }
        }
        private void toolStripButton_photo_Click(object sender, EventArgs e)
        {
            um.startGrab(0, pictureBox_getVision);
            um.startGrab(1, pictureBox_chekVision);
        }
        int sele = 0;
        private void button_move_XYZR_MouseDown(object sender, MouseEventArgs e)
        {
            ushort axis;
            try
            {
                sele = int.Parse((string)group_speed.Tag);
                int speed = 0;
                switch (sele)
                {
                    case 0: speed = define_axisData.AxisSpeed.ws_speed_fast; break;
                    case 1: speed = define_axisData.AxisSpeed.ws_speed_slow; break;
                    case 2: speed = define_axisData.AxisSpeed.ws_speed_work; break;
                }

                switch (((Button)sender).TabIndex)
                {
                    case 1:
                    case 2: axis = define_axisData.AxisNum.Axis_xx; break;
                    case 3:
                    case 4: axis = define_axisData.AxisNum.Axis_yy; break;
                    case 5:
                    case 6: axis = define_axisData.AxisNum.Axis_zz; break;
                    case 7:
                    case 8: axis = define_axisData.AxisNum.Axis_rr; break;
                    default: return;
                }
                if (sele < 2)
                {
                    bool away = ((Button)sender).TabIndex % 2 == 0;
                    um.evenMove(axis, um.getSpeed(speed), away);
                }
                else
                {
                    um.fixationMove(axis, Convert.ToInt32(textBox_length.Text));
                }
            }
            catch { MessageBox.Show("请选择运动模式"); }
        }

        private void button_MouseUp(object sender, MouseEventArgs e)
        {
            if (sele != 2) um.stopAxis();
        }
        private void radioButton_length_Click(object sender, EventArgs e)
        {
            int sele = ((RadioButton)sender).TabIndex;
            group_speed.Tag = sele.ToString();
            textBox_length.Enabled = (sele == 2);
            if (sele == 2)
            {
                textBox_length.SelectAll();
                textBox_length.Select();
            }
        }
        private void button_stop_Click(object sender, EventArgs e)
        {
            um.stopAxis();
        }
        bool isHardStart = true;
        bool isHardStop = true;
        private void timer_pos_Tick(object sender, EventArgs e)
        {
            if (um.AxisState == AxisState.RUNNING)
            {
                textBox_Xpos.Text = um.nowPos(define_axisData.AxisNum.Axis_xx);
                textBox_Ypos.Text = um.nowPos(define_axisData.AxisNum.Axis_yy);
                textBox_Zpos.Text = um.nowPos(define_axisData.AxisNum.Axis_zz);
                textBox_Rpos.Text = um.nowPos(define_axisData.AxisNum.Axis_rr);
            }
            if (LTDMC.dmc_read_inbit(0, 0) == 0 && isHardStart == true)
            {
                um.AxisState = AxisState.RUNNING;
                um.WorkState = WorkState.dostop;
                OnOffaotuwork.Set();
                thAotu = new Thread(doaotuWork);
                thAotu.IsBackground = true;
                thAotu.Start();
                isHardStart = false;
            }
            else if (LTDMC.dmc_read_inbit(0, 0) == 1 && isHardStart == false)
            {
                isHardStart = true;
            }
            if (LTDMC.dmc_read_inbit(0, 1) == 0 && isHardStop == true)
            {
                doStophome();
                doStopwork();
                isHardStart = false;
            }
            else if (LTDMC.dmc_read_inbit(0, 1) == 1 && isHardStop == false)
            {
                isHardStop = true;
            }
        }

        private void toolStripButton_new_Click(object sender, EventArgs e)
        {
            um.newCreate();
        }

        private void toolStripButton_load_Click(object sender, EventArgs e)
        {
            um.loadData();
            mForm_Config.propertyGrid_params.Refresh();
        }

        private void toolStripButton_save_Click(object sender, EventArgs e)
        {
            um.saveData();

        }
        private void toolStripButton_Min_Click(object sender, EventArgs e)
        {
            WindowState = FormWindowState.Minimized;
        }

        private void toolStripButton_Max_Click(object sender, EventArgs e)
        {
            if (WindowState == FormWindowState.Maximized)
                WindowState = FormWindowState.Normal;
            else
                WindowState = FormWindowState.Maximized;
        }
        private void toolStripButton_back_Click(object sender, EventArgs e)
        {
            Close();
        }
        #region 鼠标事件
        bool beginMove = false;//初始化鼠标位置
        int currentXPosition;
        int currentYPosition;
        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            //获取鼠标按下的位置
            if (e.Button == MouseButtons.Left)
            {
                beginMove = true;
                currentXPosition = MousePosition.X;//鼠标的x坐标为当前窗体左上角x坐标
                currentYPosition = MousePosition.Y;//鼠标的y坐标为当前窗体左上角y坐标
            }
        }
        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            //获取鼠标移动到的位置
            if (beginMove)
            {
                Left += MousePosition.X - currentXPosition;//根据鼠标x坐标确定窗体的左边坐标x
                Top += MousePosition.Y - currentYPosition;//根据鼠标的y坐标窗体的顶部，即Y坐标
                currentXPosition = MousePosition.X;
                currentYPosition = MousePosition.Y;
            }
        }
        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            //释放鼠标时的位置
            if (e.Button == MouseButtons.Left)
            {
                currentXPosition = 0; //设置初始状态
                currentYPosition = 0;
                beginMove = false;
            }
        }
        #endregion
    }
}
