using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SQLite;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace 光机电上位机控制系统
{
    public partial class Form_System : Form
    {
        use_motion um = new use_motion();
        method_Convert mc = new method_Convert();
        define_PropertySystem dps = define_PropertySystem.GetInstance();
        public Form_System()
        {
            InitializeComponent();
        }
        private void Form_System_Load(object sender, EventArgs e)
        {
            um.readgwp(lv_pos);
            propertyGrid_params.SelectedObject = dps;
            Control.CheckForIllegalCrossThreadCalls = false;

        }
        private void radio_params_Click(object sender, EventArgs e)
        {
            int index = ((RadioButton)sender).TabIndex;
            xPanderPanel1.Visible = index == 0;
            xPanderPanel1.Expand = (index == 0);
            xPanderPanel2.Visible = index == 1;
            xPanderPanel2.Expand = (index == 1);
            xPanderPanel3.Visible = index == 2;
            xPanderPanel3.Expand = (index == 2);
            xPanderPanel4.Visible = index == 3;
            xPanderPanel4.Expand = (index == 3);
            if (index == 0)
            {
                propertyGrid_params.Select();
            }
        }
        private void button_save_Click(object sender, EventArgs e)
        {
            um.intoNnewtable();
            um.readSpeed();
        }
        private void button_reload_Click(object sender, EventArgs e)
        {
            um.readData();
            propertyGrid_params.Refresh();
        }
        private void button_modifi_Click(object sender, EventArgs e)
        {
            um.modifigwp(lv_pos, Form1.form1.textBox_Xpos, Form1.form1.textBox_Ypos, Form1.form1.textBox_Zpos);
        }

        private void button_move_Click(object sender, EventArgs e)
        {
            um.AxisState = AxisState.RUNNING;
            LTDMC.dmc_pmove(0, define_axisData.AxisNum.Axis_xx, mc.RatioX(Convert.ToInt32(lv_pos.SelectedItems[0].SubItems[1].Text)), 1);
            LTDMC.dmc_pmove(0, define_axisData.AxisNum.Axis_yy, mc.RatioY(Convert.ToInt32(lv_pos.SelectedItems[0].SubItems[2].Text)), 1);
        }
        private void button_set_Click(object sender, EventArgs e)
        {
            um.loadgwp(lv_pos);
        }
        private void bt_shootA_Click(object sender, EventArgs e)
        {
            um.shootImageSA(0, Form1.form1.hWindowControl_getVision.HalconWindow);
        }
        private void bt_posleftup_Click(object sender, EventArgs e)
        {
            um.lup(lv_SA, Form1.form1.textBox_Xpos, Form1.form1.textBox_Ypos);
        }
        private void bt_posrightup_Click(object sender, EventArgs e)
        {
            um.rdown(lv_SA, Form1.form1.textBox_Xpos, Form1.form1.textBox_Ypos);
        }
        private void bt_shootB_Click(object sender, EventArgs e)
        {
            um.shootImageSB(1, Form1.form1.hWindowControl_chekVision.HalconWindow);
        }

        private void bt_positionvision_Click(object sender, EventArgs e)
        {
            um.posVision(lv_SA);
        }

        private void bt_setmodle_Click(object sender, EventArgs e)
        {
            um.setModelSB(lv_SB, Form1.form1.textBox_Xpos, Form1.form1.textBox_Ypos);
        }

        private void bt_findpos_Click(object sender, EventArgs e)
        {
            um.setPosSB(lv_SB, Form1.form1.textBox_Xpos, Form1.form1.textBox_Ypos);
        }
        private void bt_calratA_Click(object sender, EventArgs e)
        {
            um.calRataA(lv_SA, tb_XrataA, tb_YrataA);
        }
        private void bt_calratB_Click(object sender, EventArgs e)
        {
            um.calRataB(lv_SB, tb_XrataB, tb_YrataB);
        }

        private void bt_setratA_Click(object sender, EventArgs e)
        {
            um.setRataA(tb_XrataA, tb_YrataA);
        }

        private void bt_setratB_Click(object sender, EventArgs e)
        {
            um.setRataB(tb_XrataB, tb_YrataB);
        }

       
    }
}
