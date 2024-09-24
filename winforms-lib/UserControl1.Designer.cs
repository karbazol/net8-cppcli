namespace winforms_lib
{
  partial class UserControl1
  {
    /// <summary> 
    /// Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    /// <summary> 
    /// Clean up any resources being used.
    /// </summary>
    /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
    protected override void Dispose(bool disposing)
    {
      if (disposing && (components != null))
      {
        components.Dispose();
      }
      base.Dispose(disposing);
    }

    #region Component Designer generated code

    /// <summary> 
    /// Required method for Designer support - do not modify 
    /// the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent()
    {
      ListViewItem listViewItem1 = new ListViewItem(new ListViewItem.ListViewSubItem[] { new ListViewItem.ListViewSubItem(null, "Application Started", Color.Green, SystemColors.Window, new Font("Segoe UI", 9F)), new ListViewItem.ListViewSubItem(null, "Info", SystemColors.InactiveCaption, SystemColors.Window, new Font("Segoe UI", 9F)), new ListViewItem.ListViewSubItem(null, "24.09.2024 09:00:10") }, -1);
      ListViewItem listViewItem2 = new ListViewItem(new string[] { "Configuration not found", "Error", "24.09.2024 09:00:18" }, -1, Color.Red, Color.Empty, null);
      listView1 = new ListView();
      mColumnHeaderMessage = new ColumnHeader();
      mColumnHeaderPriority = new ColumnHeader();
      mColumnHeaderTimestamp = new ColumnHeader();
      SuspendLayout();
      // 
      // listView1
      // 
      listView1.Columns.AddRange(new ColumnHeader[] { mColumnHeaderMessage, mColumnHeaderPriority, mColumnHeaderTimestamp });
      listView1.Dock = DockStyle.Fill;
      listView1.Items.AddRange(new ListViewItem[] { listViewItem1, listViewItem2 });
      listView1.Location = new Point(0, 0);
      listView1.Name = "listView1";
      listView1.Size = new Size(604, 341);
      listView1.TabIndex = 0;
      listView1.UseCompatibleStateImageBehavior = false;
      listView1.View = View.Details;
      // 
      // mColumnHeaderMessage
      // 
      mColumnHeaderMessage.Text = "Message";
      mColumnHeaderMessage.Width = 240;
      // 
      // mColumnHeaderPriority
      // 
      mColumnHeaderPriority.Text = "Priority";
      // 
      // mColumnHeaderTimestamp
      // 
      mColumnHeaderTimestamp.Text = "Timestamp";
      mColumnHeaderTimestamp.Width = 150;
      // 
      // UserControl1
      // 
      AutoScaleDimensions = new SizeF(8F, 20F);
      AutoScaleMode = AutoScaleMode.Font;
      Controls.Add(listView1);
      Name = "UserControl1";
      Size = new Size(604, 341);
      ResumeLayout(false);
    }

    #endregion

    private ListView listView1;
    private ColumnHeader mColumnHeaderMessage;
    private ColumnHeader mColumnHeaderPriority;
    private ColumnHeader mColumnHeaderTimestamp;
  }
}
