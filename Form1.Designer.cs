
namespace 光机电上位机控制系统
{
    partial class Form1
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.Mdi_panelAll = new System.Windows.Forms.Panel();
            this.Mdi_panel = new System.Windows.Forms.Panel();
            this.panel3 = new System.Windows.Forms.Panel();
            this.group_speed = new System.Windows.Forms.GroupBox();
            this.radioButton_low = new System.Windows.Forms.RadioButton();
            this.radioButton_fast = new System.Windows.Forms.RadioButton();
            this.radioButton_length = new System.Windows.Forms.RadioButton();
            this.textBox_length = new System.Windows.Forms.TextBox();
            this.button_move_back_z = new System.Windows.Forms.Button();
            this.button_move_forw_z = new System.Windows.Forms.Button();
            this.button_move_r_pos = new System.Windows.Forms.Button();
            this.button_move_r_neg = new System.Windows.Forms.Button();
            this.button_move_forw_y = new System.Windows.Forms.Button();
            this.button_move_back_y = new System.Windows.Forms.Button();
            this.button_move_forw_x = new System.Windows.Forms.Button();
            this.button_stop = new System.Windows.Forms.Button();
            this.button_move_back_x = new System.Windows.Forms.Button();
            this.panel4 = new System.Windows.Forms.Panel();
            this.textBox_Rpos = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.textBox_Zpos = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.textBox_Ypos = new System.Windows.Forms.TextBox();
            this.textBox_Xpos = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.tableLayoutPanel3 = new System.Windows.Forms.TableLayoutPanel();
            this.hWindowControl_chekVision = new HalconDotNet.HWindowControl();
            this.pictureBox_chekVision = new System.Windows.Forms.PictureBox();
            this.pictureBox_getVision = new System.Windows.Forms.PictureBox();
            this.hWindowControl_getVision = new HalconDotNet.HWindowControl();
            this.tableLayoutPanel4 = new System.Windows.Forms.TableLayoutPanel();
            this.toolStrip1 = new System.Windows.Forms.ToolStrip();
            this.toolStripButton_start = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton_stop = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton_home = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripButton_product = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton_system = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripButton_photo = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripButton_new = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton_load = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton_save = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator4 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripButton_watch = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton_IO = new System.Windows.Forms.ToolStripButton();
            this.toolStripSeparator5 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripButton_Min = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton_Max = new System.Windows.Forms.ToolStripButton();
            this.toolStripButton_back = new System.Windows.Forms.ToolStripButton();
            this.panel1 = new System.Windows.Forms.Panel();
            this.label3 = new System.Windows.Forms.Label();
            this.timer_pos = new System.Windows.Forms.Timer(this.components);
            this.tableLayoutPanel1.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            this.Mdi_panelAll.SuspendLayout();
            this.panel3.SuspendLayout();
            this.group_speed.SuspendLayout();
            this.panel4.SuspendLayout();
            this.tableLayoutPanel3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_chekVision)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_getVision)).BeginInit();
            this.tableLayoutPanel4.SuspendLayout();
            this.toolStrip1.SuspendLayout();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 1;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.Controls.Add(this.tableLayoutPanel2, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.tableLayoutPanel4, 0, 0);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 2;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 80F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(1700, 1102);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.ColumnCount = 2;
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Absolute, 425F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel2.Controls.Add(this.Mdi_panelAll, 0, 0);
            this.tableLayoutPanel2.Controls.Add(this.tableLayoutPanel3, 1, 0);
            this.tableLayoutPanel2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel2.Location = new System.Drawing.Point(3, 83);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 1;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel2.Size = new System.Drawing.Size(1694, 1016);
            this.tableLayoutPanel2.TabIndex = 1;
            // 
            // Mdi_panelAll
            // 
            this.Mdi_panelAll.Controls.Add(this.Mdi_panel);
            this.Mdi_panelAll.Controls.Add(this.panel3);
            this.Mdi_panelAll.Controls.Add(this.panel4);
            this.Mdi_panelAll.Dock = System.Windows.Forms.DockStyle.Fill;
            this.Mdi_panelAll.Location = new System.Drawing.Point(3, 3);
            this.Mdi_panelAll.Name = "Mdi_panelAll";
            this.Mdi_panelAll.Size = new System.Drawing.Size(419, 1010);
            this.Mdi_panelAll.TabIndex = 0;
            // 
            // Mdi_panel
            // 
            this.Mdi_panel.BackColor = System.Drawing.SystemColors.Control;
            this.Mdi_panel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.Mdi_panel.Location = new System.Drawing.Point(0, 233);
            this.Mdi_panel.Name = "Mdi_panel";
            this.Mdi_panel.Size = new System.Drawing.Size(419, 777);
            this.Mdi_panel.TabIndex = 5;
            // 
            // panel3
            // 
            this.panel3.Controls.Add(this.group_speed);
            this.panel3.Controls.Add(this.button_move_back_z);
            this.panel3.Controls.Add(this.button_move_forw_z);
            this.panel3.Controls.Add(this.button_move_r_pos);
            this.panel3.Controls.Add(this.button_move_r_neg);
            this.panel3.Controls.Add(this.button_move_forw_y);
            this.panel3.Controls.Add(this.button_move_back_y);
            this.panel3.Controls.Add(this.button_move_forw_x);
            this.panel3.Controls.Add(this.button_stop);
            this.panel3.Controls.Add(this.button_move_back_x);
            this.panel3.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel3.Location = new System.Drawing.Point(0, 50);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(419, 183);
            this.panel3.TabIndex = 4;
            // 
            // group_speed
            // 
            this.group_speed.Controls.Add(this.radioButton_low);
            this.group_speed.Controls.Add(this.radioButton_fast);
            this.group_speed.Controls.Add(this.radioButton_length);
            this.group_speed.Controls.Add(this.textBox_length);
            this.group_speed.Dock = System.Windows.Forms.DockStyle.Right;
            this.group_speed.Location = new System.Drawing.Point(263, 0);
            this.group_speed.Name = "group_speed";
            this.group_speed.Size = new System.Drawing.Size(156, 183);
            this.group_speed.TabIndex = 18;
            this.group_speed.TabStop = false;
            // 
            // radioButton_low
            // 
            this.radioButton_low.AutoSize = true;
            this.radioButton_low.Location = new System.Drawing.Point(20, 74);
            this.radioButton_low.Name = "radioButton_low";
            this.radioButton_low.Size = new System.Drawing.Size(88, 19);
            this.radioButton_low.TabIndex = 1;
            this.radioButton_low.Text = "慢速点动";
            this.radioButton_low.UseVisualStyleBackColor = true;
            this.radioButton_low.Click += new System.EventHandler(this.radioButton_length_Click);
            // 
            // radioButton_fast
            // 
            this.radioButton_fast.AutoSize = true;
            this.radioButton_fast.Location = new System.Drawing.Point(20, 25);
            this.radioButton_fast.Name = "radioButton_fast";
            this.radioButton_fast.Size = new System.Drawing.Size(88, 19);
            this.radioButton_fast.TabIndex = 0;
            this.radioButton_fast.Text = "快速点动";
            this.radioButton_fast.UseVisualStyleBackColor = true;
            this.radioButton_fast.Click += new System.EventHandler(this.radioButton_length_Click);
            // 
            // radioButton_length
            // 
            this.radioButton_length.AutoSize = true;
            this.radioButton_length.Location = new System.Drawing.Point(20, 124);
            this.radioButton_length.Name = "radioButton_length";
            this.radioButton_length.Size = new System.Drawing.Size(58, 19);
            this.radioButton_length.TabIndex = 2;
            this.radioButton_length.Text = "定长";
            this.radioButton_length.UseVisualStyleBackColor = true;
            this.radioButton_length.Click += new System.EventHandler(this.radioButton_length_Click);
            // 
            // textBox_length
            // 
            this.textBox_length.Enabled = false;
            this.textBox_length.Location = new System.Drawing.Point(84, 118);
            this.textBox_length.Name = "textBox_length";
            this.textBox_length.Size = new System.Drawing.Size(66, 25);
            this.textBox_length.TabIndex = 3;
            // 
            // button_move_back_z
            // 
            this.button_move_back_z.BackColor = System.Drawing.Color.Transparent;
            this.button_move_back_z.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button_move_back_z.BackgroundImage")));
            this.button_move_back_z.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button_move_back_z.Location = new System.Drawing.Point(181, 8);
            this.button_move_back_z.Name = "button_move_back_z";
            this.button_move_back_z.Size = new System.Drawing.Size(50, 50);
            this.button_move_back_z.TabIndex = 5;
            this.button_move_back_z.Text = "Z+";
            this.button_move_back_z.UseVisualStyleBackColor = false;
            this.button_move_back_z.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button_move_XYZR_MouseDown);
            this.button_move_back_z.MouseUp += new System.Windows.Forms.MouseEventHandler(this.button_MouseUp);
            // 
            // button_move_forw_z
            // 
            this.button_move_forw_z.BackColor = System.Drawing.Color.Transparent;
            this.button_move_forw_z.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button_move_forw_z.BackgroundImage")));
            this.button_move_forw_z.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.button_move_forw_z.Location = new System.Drawing.Point(181, 64);
            this.button_move_forw_z.Name = "button_move_forw_z";
            this.button_move_forw_z.Size = new System.Drawing.Size(50, 50);
            this.button_move_forw_z.TabIndex = 6;
            this.button_move_forw_z.Text = "Z-";
            this.button_move_forw_z.UseVisualStyleBackColor = false;
            this.button_move_forw_z.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button_move_XYZR_MouseDown);
            this.button_move_forw_z.MouseUp += new System.Windows.Forms.MouseEventHandler(this.button_MouseUp);
            // 
            // button_move_r_pos
            // 
            this.button_move_r_pos.BackColor = System.Drawing.Color.Transparent;
            this.button_move_r_pos.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button_move_r_pos.BackgroundImage")));
            this.button_move_r_pos.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button_move_r_pos.Location = new System.Drawing.Point(181, 120);
            this.button_move_r_pos.Name = "button_move_r_pos";
            this.button_move_r_pos.Size = new System.Drawing.Size(50, 50);
            this.button_move_r_pos.TabIndex = 8;
            this.button_move_r_pos.Text = "R";
            this.button_move_r_pos.UseVisualStyleBackColor = false;
            this.button_move_r_pos.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button_move_XYZR_MouseDown);
            this.button_move_r_pos.MouseUp += new System.Windows.Forms.MouseEventHandler(this.button_MouseUp);
            // 
            // button_move_r_neg
            // 
            this.button_move_r_neg.BackColor = System.Drawing.Color.Transparent;
            this.button_move_r_neg.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button_move_r_neg.BackgroundImage")));
            this.button_move_r_neg.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button_move_r_neg.Location = new System.Drawing.Point(124, 120);
            this.button_move_r_neg.Name = "button_move_r_neg";
            this.button_move_r_neg.Size = new System.Drawing.Size(50, 50);
            this.button_move_r_neg.TabIndex = 7;
            this.button_move_r_neg.Text = "R";
            this.button_move_r_neg.UseVisualStyleBackColor = false;
            this.button_move_r_neg.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button_move_XYZR_MouseDown);
            this.button_move_r_neg.MouseUp += new System.Windows.Forms.MouseEventHandler(this.button_MouseUp);
            // 
            // button_move_forw_y
            // 
            this.button_move_forw_y.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button_move_forw_y.BackgroundImage")));
            this.button_move_forw_y.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button_move_forw_y.Location = new System.Drawing.Point(124, 64);
            this.button_move_forw_y.Name = "button_move_forw_y";
            this.button_move_forw_y.Size = new System.Drawing.Size(50, 50);
            this.button_move_forw_y.TabIndex = 4;
            this.button_move_forw_y.Text = "Y+";
            this.button_move_forw_y.UseVisualStyleBackColor = true;
            this.button_move_forw_y.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button_move_XYZR_MouseDown);
            this.button_move_forw_y.MouseUp += new System.Windows.Forms.MouseEventHandler(this.button_MouseUp);
            // 
            // button_move_back_y
            // 
            this.button_move_back_y.BackColor = System.Drawing.Color.Transparent;
            this.button_move_back_y.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button_move_back_y.BackgroundImage")));
            this.button_move_back_y.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button_move_back_y.Location = new System.Drawing.Point(12, 64);
            this.button_move_back_y.Name = "button_move_back_y";
            this.button_move_back_y.Size = new System.Drawing.Size(50, 50);
            this.button_move_back_y.TabIndex = 3;
            this.button_move_back_y.Text = "Y-";
            this.button_move_back_y.UseVisualStyleBackColor = false;
            this.button_move_back_y.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button_move_XYZR_MouseDown);
            this.button_move_back_y.MouseUp += new System.Windows.Forms.MouseEventHandler(this.button_MouseUp);
            // 
            // button_move_forw_x
            // 
            this.button_move_forw_x.BackColor = System.Drawing.Color.Transparent;
            this.button_move_forw_x.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button_move_forw_x.BackgroundImage")));
            this.button_move_forw_x.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button_move_forw_x.Location = new System.Drawing.Point(68, 120);
            this.button_move_forw_x.Name = "button_move_forw_x";
            this.button_move_forw_x.Size = new System.Drawing.Size(50, 50);
            this.button_move_forw_x.TabIndex = 2;
            this.button_move_forw_x.Text = "X-";
            this.button_move_forw_x.UseVisualStyleBackColor = false;
            this.button_move_forw_x.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button_move_XYZR_MouseDown);
            this.button_move_forw_x.MouseUp += new System.Windows.Forms.MouseEventHandler(this.button_MouseUp);
            // 
            // button_stop
            // 
            this.button_stop.BackColor = System.Drawing.Color.Transparent;
            this.button_stop.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button_stop.BackgroundImage")));
            this.button_stop.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button_stop.Location = new System.Drawing.Point(68, 64);
            this.button_stop.Name = "button_stop";
            this.button_stop.Size = new System.Drawing.Size(50, 50);
            this.button_stop.TabIndex = 9;
            this.button_stop.UseVisualStyleBackColor = false;
            this.button_stop.Click += new System.EventHandler(this.button_stop_Click);
            // 
            // button_move_back_x
            // 
            this.button_move_back_x.BackColor = System.Drawing.Color.Transparent;
            this.button_move_back_x.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("button_move_back_x.BackgroundImage")));
            this.button_move_back_x.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.button_move_back_x.Location = new System.Drawing.Point(68, 7);
            this.button_move_back_x.Margin = new System.Windows.Forms.Padding(4);
            this.button_move_back_x.Name = "button_move_back_x";
            this.button_move_back_x.Size = new System.Drawing.Size(50, 50);
            this.button_move_back_x.TabIndex = 1;
            this.button_move_back_x.TabStop = false;
            this.button_move_back_x.Text = "X+";
            this.button_move_back_x.UseVisualStyleBackColor = false;
            this.button_move_back_x.MouseDown += new System.Windows.Forms.MouseEventHandler(this.button_move_XYZR_MouseDown);
            this.button_move_back_x.MouseUp += new System.Windows.Forms.MouseEventHandler(this.button_MouseUp);
            // 
            // panel4
            // 
            this.panel4.Controls.Add(this.textBox_Rpos);
            this.panel4.Controls.Add(this.label6);
            this.panel4.Controls.Add(this.textBox_Zpos);
            this.panel4.Controls.Add(this.label4);
            this.panel4.Controls.Add(this.textBox_Ypos);
            this.panel4.Controls.Add(this.textBox_Xpos);
            this.panel4.Controls.Add(this.label2);
            this.panel4.Controls.Add(this.label1);
            this.panel4.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel4.Location = new System.Drawing.Point(0, 0);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(419, 50);
            this.panel4.TabIndex = 3;
            // 
            // textBox_Rpos
            // 
            this.textBox_Rpos.Location = new System.Drawing.Point(338, 12);
            this.textBox_Rpos.Name = "textBox_Rpos";
            this.textBox_Rpos.ReadOnly = true;
            this.textBox_Rpos.Size = new System.Drawing.Size(66, 25);
            this.textBox_Rpos.TabIndex = 10;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(309, 15);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(23, 15);
            this.label6.TabIndex = 8;
            this.label6.Text = "R:";
            // 
            // textBox_Zpos
            // 
            this.textBox_Zpos.Location = new System.Drawing.Point(237, 12);
            this.textBox_Zpos.Name = "textBox_Zpos";
            this.textBox_Zpos.ReadOnly = true;
            this.textBox_Zpos.Size = new System.Drawing.Size(66, 25);
            this.textBox_Zpos.TabIndex = 6;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(208, 15);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(23, 15);
            this.label4.TabIndex = 4;
            this.label4.Text = "Z:";
            // 
            // textBox_Ypos
            // 
            this.textBox_Ypos.Location = new System.Drawing.Point(130, 12);
            this.textBox_Ypos.Name = "textBox_Ypos";
            this.textBox_Ypos.ReadOnly = true;
            this.textBox_Ypos.Size = new System.Drawing.Size(66, 25);
            this.textBox_Ypos.TabIndex = 3;
            // 
            // textBox_Xpos
            // 
            this.textBox_Xpos.Location = new System.Drawing.Point(35, 12);
            this.textBox_Xpos.Name = "textBox_Xpos";
            this.textBox_Xpos.ReadOnly = true;
            this.textBox_Xpos.Size = new System.Drawing.Size(66, 25);
            this.textBox_Xpos.TabIndex = 2;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(107, 15);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(23, 15);
            this.label2.TabIndex = 1;
            this.label2.Text = "Y:";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(23, 15);
            this.label1.TabIndex = 0;
            this.label1.Text = "X:";
            // 
            // tableLayoutPanel3
            // 
            this.tableLayoutPanel3.ColumnCount = 2;
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel3.Controls.Add(this.hWindowControl_chekVision, 1, 1);
            this.tableLayoutPanel3.Controls.Add(this.pictureBox_chekVision, 1, 0);
            this.tableLayoutPanel3.Controls.Add(this.pictureBox_getVision, 0, 0);
            this.tableLayoutPanel3.Controls.Add(this.hWindowControl_getVision, 0, 1);
            this.tableLayoutPanel3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel3.Location = new System.Drawing.Point(428, 3);
            this.tableLayoutPanel3.Name = "tableLayoutPanel3";
            this.tableLayoutPanel3.RowCount = 2;
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel3.Size = new System.Drawing.Size(1263, 1010);
            this.tableLayoutPanel3.TabIndex = 1;
            // 
            // hWindowControl_chekVision
            // 
            this.hWindowControl_chekVision.BackColor = System.Drawing.Color.Black;
            this.hWindowControl_chekVision.BorderColor = System.Drawing.Color.Black;
            this.hWindowControl_chekVision.Dock = System.Windows.Forms.DockStyle.Fill;
            this.hWindowControl_chekVision.ImagePart = new System.Drawing.Rectangle(0, 0, 640, 480);
            this.hWindowControl_chekVision.Location = new System.Drawing.Point(634, 508);
            this.hWindowControl_chekVision.Name = "hWindowControl_chekVision";
            this.hWindowControl_chekVision.Size = new System.Drawing.Size(626, 499);
            this.hWindowControl_chekVision.TabIndex = 3;
            this.hWindowControl_chekVision.WindowSize = new System.Drawing.Size(626, 499);
            // 
            // pictureBox_chekVision
            // 
            this.pictureBox_chekVision.BackColor = System.Drawing.Color.Black;
            this.pictureBox_chekVision.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pictureBox_chekVision.Location = new System.Drawing.Point(634, 3);
            this.pictureBox_chekVision.Name = "pictureBox_chekVision";
            this.pictureBox_chekVision.Size = new System.Drawing.Size(626, 499);
            this.pictureBox_chekVision.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_chekVision.TabIndex = 1;
            this.pictureBox_chekVision.TabStop = false;
            // 
            // pictureBox_getVision
            // 
            this.pictureBox_getVision.BackColor = System.Drawing.Color.Black;
            this.pictureBox_getVision.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pictureBox_getVision.Location = new System.Drawing.Point(3, 3);
            this.pictureBox_getVision.Name = "pictureBox_getVision";
            this.pictureBox_getVision.Size = new System.Drawing.Size(625, 499);
            this.pictureBox_getVision.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox_getVision.TabIndex = 0;
            this.pictureBox_getVision.TabStop = false;
            // 
            // hWindowControl_getVision
            // 
            this.hWindowControl_getVision.BackColor = System.Drawing.Color.Black;
            this.hWindowControl_getVision.BorderColor = System.Drawing.Color.Black;
            this.hWindowControl_getVision.Dock = System.Windows.Forms.DockStyle.Fill;
            this.hWindowControl_getVision.ImagePart = new System.Drawing.Rectangle(0, 0, 640, 480);
            this.hWindowControl_getVision.Location = new System.Drawing.Point(3, 508);
            this.hWindowControl_getVision.Name = "hWindowControl_getVision";
            this.hWindowControl_getVision.Size = new System.Drawing.Size(625, 499);
            this.hWindowControl_getVision.TabIndex = 2;
            this.hWindowControl_getVision.WindowSize = new System.Drawing.Size(625, 499);
            // 
            // tableLayoutPanel4
            // 
            this.tableLayoutPanel4.ColumnCount = 2;
            this.tableLayoutPanel4.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 75.27757F));
            this.tableLayoutPanel4.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 24.72243F));
            this.tableLayoutPanel4.Controls.Add(this.toolStrip1, 0, 0);
            this.tableLayoutPanel4.Controls.Add(this.panel1, 1, 0);
            this.tableLayoutPanel4.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel4.Location = new System.Drawing.Point(3, 3);
            this.tableLayoutPanel4.Name = "tableLayoutPanel4";
            this.tableLayoutPanel4.RowCount = 1;
            this.tableLayoutPanel4.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel4.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 74F));
            this.tableLayoutPanel4.Size = new System.Drawing.Size(1694, 74);
            this.tableLayoutPanel4.TabIndex = 2;
            // 
            // toolStrip1
            // 
            this.toolStrip1.AutoSize = false;
            this.toolStrip1.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.toolStrip1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.toolStrip1.GripStyle = System.Windows.Forms.ToolStripGripStyle.Hidden;
            this.toolStrip1.ImageScalingSize = new System.Drawing.Size(46, 46);
            this.toolStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripButton_start,
            this.toolStripButton_stop,
            this.toolStripButton_home,
            this.toolStripSeparator1,
            this.toolStripButton_product,
            this.toolStripButton_system,
            this.toolStripSeparator2,
            this.toolStripButton_photo,
            this.toolStripSeparator3,
            this.toolStripButton_new,
            this.toolStripButton_load,
            this.toolStripButton_save,
            this.toolStripSeparator4,
            this.toolStripButton_watch,
            this.toolStripButton_IO,
            this.toolStripSeparator5,
            this.toolStripButton_Min,
            this.toolStripButton_Max,
            this.toolStripButton_back});
            this.toolStrip1.Location = new System.Drawing.Point(0, 0);
            this.toolStrip1.Name = "toolStrip1";
            this.toolStrip1.RenderMode = System.Windows.Forms.ToolStripRenderMode.System;
            this.toolStrip1.ShowItemToolTips = false;
            this.toolStrip1.Size = new System.Drawing.Size(1275, 74);
            this.toolStrip1.TabIndex = 0;
            // 
            // toolStripButton_start
            // 
            this.toolStripButton_start.AutoSize = false;
            this.toolStripButton_start.BackColor = System.Drawing.Color.Transparent;
            this.toolStripButton_start.Font = new System.Drawing.Font("Microsoft YaHei UI", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.toolStripButton_start.ForeColor = System.Drawing.Color.Black;
            this.toolStripButton_start.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton_start.Image")));
            this.toolStripButton_start.ImageTransparentColor = System.Drawing.Color.Transparent;
            this.toolStripButton_start.Name = "toolStripButton_start";
            this.toolStripButton_start.Size = new System.Drawing.Size(65, 65);
            this.toolStripButton_start.Text = "运行";
            this.toolStripButton_start.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.toolStripButton_start.Click += new System.EventHandler(this.toolStripButton_start_Click);
            // 
            // toolStripButton_stop
            // 
            this.toolStripButton_stop.AutoSize = false;
            this.toolStripButton_stop.Font = new System.Drawing.Font("Microsoft YaHei UI", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.toolStripButton_stop.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton_stop.Image")));
            this.toolStripButton_stop.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton_stop.Name = "toolStripButton_stop";
            this.toolStripButton_stop.Size = new System.Drawing.Size(65, 65);
            this.toolStripButton_stop.Text = "停止";
            this.toolStripButton_stop.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.toolStripButton_stop.Click += new System.EventHandler(this.toolStripButton_stop_Click);
            // 
            // toolStripButton_home
            // 
            this.toolStripButton_home.AutoSize = false;
            this.toolStripButton_home.Font = new System.Drawing.Font("Microsoft YaHei UI", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.toolStripButton_home.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton_home.Image")));
            this.toolStripButton_home.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton_home.Name = "toolStripButton_home";
            this.toolStripButton_home.Size = new System.Drawing.Size(65, 65);
            this.toolStripButton_home.Text = "复位";
            this.toolStripButton_home.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.toolStripButton_home.Click += new System.EventHandler(this.toolStripButton_home_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(6, 74);
            // 
            // toolStripButton_product
            // 
            this.toolStripButton_product.AutoSize = false;
            this.toolStripButton_product.Font = new System.Drawing.Font("Microsoft YaHei UI", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.toolStripButton_product.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton_product.Image")));
            this.toolStripButton_product.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton_product.Name = "toolStripButton_product";
            this.toolStripButton_product.Size = new System.Drawing.Size(65, 65);
            this.toolStripButton_product.Text = "产品";
            this.toolStripButton_product.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.toolStripButton_product.Click += new System.EventHandler(this.toolStripButton_product_Click);
            // 
            // toolStripButton_system
            // 
            this.toolStripButton_system.AutoSize = false;
            this.toolStripButton_system.Font = new System.Drawing.Font("Microsoft YaHei UI", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.toolStripButton_system.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton_system.Image")));
            this.toolStripButton_system.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton_system.Name = "toolStripButton_system";
            this.toolStripButton_system.Size = new System.Drawing.Size(65, 65);
            this.toolStripButton_system.Text = "系统";
            this.toolStripButton_system.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.toolStripButton_system.Click += new System.EventHandler(this.toolStripButton_system_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(6, 74);
            // 
            // toolStripButton_photo
            // 
            this.toolStripButton_photo.AutoSize = false;
            this.toolStripButton_photo.Font = new System.Drawing.Font("Microsoft YaHei UI", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.toolStripButton_photo.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton_photo.Image")));
            this.toolStripButton_photo.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton_photo.Name = "toolStripButton_photo";
            this.toolStripButton_photo.Size = new System.Drawing.Size(65, 65);
            this.toolStripButton_photo.Text = "实时";
            this.toolStripButton_photo.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.toolStripButton_photo.Click += new System.EventHandler(this.toolStripButton_photo_Click);
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(6, 74);
            // 
            // toolStripButton_new
            // 
            this.toolStripButton_new.AutoSize = false;
            this.toolStripButton_new.Font = new System.Drawing.Font("Microsoft YaHei UI", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.toolStripButton_new.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton_new.Image")));
            this.toolStripButton_new.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton_new.Name = "toolStripButton_new";
            this.toolStripButton_new.Size = new System.Drawing.Size(65, 65);
            this.toolStripButton_new.Text = "新建";
            this.toolStripButton_new.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.toolStripButton_new.Click += new System.EventHandler(this.toolStripButton_new_Click);
            // 
            // toolStripButton_load
            // 
            this.toolStripButton_load.AutoSize = false;
            this.toolStripButton_load.Font = new System.Drawing.Font("Microsoft YaHei UI", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.toolStripButton_load.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton_load.Image")));
            this.toolStripButton_load.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton_load.Name = "toolStripButton_load";
            this.toolStripButton_load.Size = new System.Drawing.Size(65, 65);
            this.toolStripButton_load.Text = "载入";
            this.toolStripButton_load.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.toolStripButton_load.Click += new System.EventHandler(this.toolStripButton_load_Click);
            // 
            // toolStripButton_save
            // 
            this.toolStripButton_save.AutoSize = false;
            this.toolStripButton_save.Font = new System.Drawing.Font("Microsoft YaHei UI", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.toolStripButton_save.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton_save.Image")));
            this.toolStripButton_save.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton_save.Name = "toolStripButton_save";
            this.toolStripButton_save.Size = new System.Drawing.Size(65, 65);
            this.toolStripButton_save.Text = "保存";
            this.toolStripButton_save.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.toolStripButton_save.Click += new System.EventHandler(this.toolStripButton_save_Click);
            // 
            // toolStripSeparator4
            // 
            this.toolStripSeparator4.Name = "toolStripSeparator4";
            this.toolStripSeparator4.Size = new System.Drawing.Size(6, 74);
            // 
            // toolStripButton_watch
            // 
            this.toolStripButton_watch.AutoSize = false;
            this.toolStripButton_watch.Font = new System.Drawing.Font("Microsoft YaHei UI", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.toolStripButton_watch.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton_watch.Image")));
            this.toolStripButton_watch.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton_watch.Name = "toolStripButton_watch";
            this.toolStripButton_watch.Size = new System.Drawing.Size(65, 65);
            this.toolStripButton_watch.Text = "检测";
            this.toolStripButton_watch.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            // 
            // toolStripButton_IO
            // 
            this.toolStripButton_IO.AutoSize = false;
            this.toolStripButton_IO.Font = new System.Drawing.Font("Microsoft YaHei UI", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.toolStripButton_IO.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton_IO.Image")));
            this.toolStripButton_IO.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton_IO.Name = "toolStripButton_IO";
            this.toolStripButton_IO.Size = new System.Drawing.Size(65, 65);
            this.toolStripButton_IO.Text = "IO";
            this.toolStripButton_IO.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            // 
            // toolStripSeparator5
            // 
            this.toolStripSeparator5.Name = "toolStripSeparator5";
            this.toolStripSeparator5.Size = new System.Drawing.Size(6, 74);
            // 
            // toolStripButton_Min
            // 
            this.toolStripButton_Min.AutoSize = false;
            this.toolStripButton_Min.Font = new System.Drawing.Font("Microsoft YaHei UI", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.toolStripButton_Min.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton_Min.Image")));
            this.toolStripButton_Min.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton_Min.Name = "toolStripButton_Min";
            this.toolStripButton_Min.Size = new System.Drawing.Size(65, 65);
            this.toolStripButton_Min.Text = "聚焦";
            this.toolStripButton_Min.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.toolStripButton_Min.Click += new System.EventHandler(this.toolStripButton_Min_Click);
            // 
            // toolStripButton_Max
            // 
            this.toolStripButton_Max.AutoSize = false;
            this.toolStripButton_Max.Font = new System.Drawing.Font("Microsoft YaHei UI", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.toolStripButton_Max.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton_Max.Image")));
            this.toolStripButton_Max.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton_Max.Name = "toolStripButton_Max";
            this.toolStripButton_Max.Size = new System.Drawing.Size(65, 65);
            this.toolStripButton_Max.Text = "缩放";
            this.toolStripButton_Max.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.toolStripButton_Max.Click += new System.EventHandler(this.toolStripButton_Max_Click);
            // 
            // toolStripButton_back
            // 
            this.toolStripButton_back.AutoSize = false;
            this.toolStripButton_back.Font = new System.Drawing.Font("Microsoft YaHei UI", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.toolStripButton_back.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButton_back.Image")));
            this.toolStripButton_back.ImageTransparentColor = System.Drawing.Color.Magenta;
            this.toolStripButton_back.Name = "toolStripButton_back";
            this.toolStripButton_back.Size = new System.Drawing.Size(65, 65);
            this.toolStripButton_back.Text = "退出";
            this.toolStripButton_back.TextImageRelation = System.Windows.Forms.TextImageRelation.ImageAboveText;
            this.toolStripButton_back.Click += new System.EventHandler(this.toolStripButton_back_Click);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.label3);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel1.Location = new System.Drawing.Point(1278, 3);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(413, 68);
            this.panel1.TabIndex = 1;
            this.panel1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseDown);
            this.panel1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseMove);
            this.panel1.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseUp);
            // 
            // label3
            // 
            this.label3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.label3.Font = new System.Drawing.Font("宋体", 13.8F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.label3.Image = ((System.Drawing.Image)(resources.GetObject("label3.Image")));
            this.label3.Location = new System.Drawing.Point(0, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(413, 68);
            this.label3.TabIndex = 0;
            this.label3.Text = "贴装机控制系统";
            this.label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.label3.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseDown);
            this.label3.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseMove);
            this.label3.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseUp);
            // 
            // timer_pos
            // 
            this.timer_pos.Interval = 10;
            this.timer_pos.Tick += new System.EventHandler(this.timer_pos_Tick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1700, 1102);
            this.Controls.Add(this.tableLayoutPanel1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "光机电上位机";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel2.ResumeLayout(false);
            this.Mdi_panelAll.ResumeLayout(false);
            this.panel3.ResumeLayout(false);
            this.group_speed.ResumeLayout(false);
            this.group_speed.PerformLayout();
            this.panel4.ResumeLayout(false);
            this.panel4.PerformLayout();
            this.tableLayoutPanel3.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_chekVision)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox_getVision)).EndInit();
            this.tableLayoutPanel4.ResumeLayout(false);
            this.toolStrip1.ResumeLayout(false);
            this.toolStrip1.PerformLayout();
            this.panel1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.ToolStrip toolStrip1;
        private System.Windows.Forms.ToolStripButton toolStripButton_start;
        private System.Windows.Forms.ToolStripButton toolStripButton_stop;
        private System.Windows.Forms.ToolStripButton toolStripButton_home;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripButton toolStripButton_product;
        private System.Windows.Forms.ToolStripButton toolStripButton_system;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripButton toolStripButton_photo;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripButton toolStripButton_new;
        private System.Windows.Forms.ToolStripButton toolStripButton_load;
        private System.Windows.Forms.ToolStripButton toolStripButton_save;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator4;
        private System.Windows.Forms.ToolStripButton toolStripButton_watch;
        private System.Windows.Forms.ToolStripButton toolStripButton_IO;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator5;
        private System.Windows.Forms.ToolStripButton toolStripButton_back;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.Panel Mdi_panelAll;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel3;
        private System.Windows.Forms.PictureBox pictureBox_chekVision;
        private System.Windows.Forms.PictureBox pictureBox_getVision;
        public HalconDotNet.HWindowControl hWindowControl_chekVision;
        public HalconDotNet.HWindowControl hWindowControl_getVision;
        private System.Windows.Forms.Panel panel4;
        public System.Windows.Forms.TextBox textBox_Rpos;
        private System.Windows.Forms.Label label6;
        public System.Windows.Forms.TextBox textBox_Zpos;
        private System.Windows.Forms.Label label4;
        public System.Windows.Forms.TextBox textBox_Ypos;
        public System.Windows.Forms.TextBox textBox_Xpos;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.GroupBox group_speed;
        private System.Windows.Forms.RadioButton radioButton_low;
        private System.Windows.Forms.RadioButton radioButton_fast;
        private System.Windows.Forms.RadioButton radioButton_length;
        private System.Windows.Forms.TextBox textBox_length;
        private System.Windows.Forms.Button button_move_back_z;
        private System.Windows.Forms.Button button_move_forw_z;
        private System.Windows.Forms.Button button_move_r_pos;
        private System.Windows.Forms.Button button_move_r_neg;
        private System.Windows.Forms.Button button_move_forw_y;
        private System.Windows.Forms.Button button_move_back_y;
        private System.Windows.Forms.Button button_move_forw_x;
        private System.Windows.Forms.Button button_stop;
        private System.Windows.Forms.Button button_move_back_x;
        private System.Windows.Forms.Panel Mdi_panel;
        public System.Windows.Forms.Timer timer_pos;
        private System.Windows.Forms.ToolStripButton toolStripButton_Min;
        private System.Windows.Forms.ToolStripButton toolStripButton_Max;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel4;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label3;
    }
}

