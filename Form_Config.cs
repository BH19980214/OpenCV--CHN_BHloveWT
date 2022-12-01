using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 光机电上位机控制系统
{
    public partial class Form_Config : Form
    {
        public Form_Config()
        {
            InitializeComponent();
        }
        define_PropertyConfig dpc = define_PropertyConfig.GetInstance();
        use_motion um = new use_motion();
        private void Form_Config_Load(object sender, EventArgs e)
        {
            propertyGrid_params.SelectedObject = dpc;
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
            if (index == 0)
            {
                propertyGrid_params.Select();
            }
        }
        private void bt_shootA_Click(object sender, EventArgs e)
        {
            um.shootImageCA(0, Form1.form1.hWindowControl_getVision.HalconWindow);
        }
        private void bt_shootB_Click(object sender, EventArgs e)
        {
            um.shootImageCB(1, Form1.form1.hWindowControl_chekVision.HalconWindow);
        }

        private void bt_setmodelA_Click(object sender, EventArgs e)
        {
            um.setModelCA(lv_CA);
        }
        private void bt_setmodelB_Click(object sender, EventArgs e)
        {
            um.setModelCB(lv_CB);
        }

        private void bt_measureposA_Click(object sender, EventArgs e)
        {
            um.setPosCA(lv_CA);
            um.measurePos(lv_CA);
        }
        private void bt_measureposB_Click(object sender, EventArgs e)
        {
            um.setPosCB(lv_CB);
            um.measurePos(lv_CB);
        }

        private void bt_setpropertyA_Click(object sender, EventArgs e)
        {
            um.setModelA(lv_CA);
        }
        private void bt_setpropertyB_Click(object sender, EventArgs e)
        {
            um.setModelB(lv_CB);
        }

        private void bt_saveModel_Click(object sender, EventArgs e)
        {
            um.saveModelA();
        }
        private void bt_loadModel_Click(object sender, EventArgs e)
        {
            um.loadModelA();
        }
        private void bt_saveModelB_Click(object sender, EventArgs e)
        {
            um.saveModelB();
        }
        private void bt_loadModelB_Click(object sender, EventArgs e)
        {
            um.loadModelB();
        }

        
    }
}
