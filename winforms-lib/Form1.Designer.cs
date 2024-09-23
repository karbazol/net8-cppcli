namespace winforms_lib
{
  partial class Form1
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

    #region Windows Form Designer generated code

    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent()
    {
      buttonOk = new Button();
      buttonCancel = new Button();
      SuspendLayout();
      // 
      // buttonOk
      // 
      buttonOk.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
      buttonOk.DialogResult = DialogResult.OK;
      buttonOk.Location = new Point(130, 163);
      buttonOk.Name = "buttonOk";
      buttonOk.Size = new Size(75, 23);
      buttonOk.TabIndex = 0;
      buttonOk.Text = "Ok";
      buttonOk.UseVisualStyleBackColor = true;
      // 
      // buttonCancel
      // 
      buttonCancel.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
      buttonCancel.DialogResult = DialogResult.Cancel;
      buttonCancel.Location = new Point(225, 163);
      buttonCancel.Name = "buttonCancel";
      buttonCancel.Size = new Size(75, 23);
      buttonCancel.TabIndex = 1;
      buttonCancel.Text = "Cancel";
      buttonCancel.UseVisualStyleBackColor = true;
      // 
      // Form1
      // 
      AcceptButton = buttonOk;
      AutoScaleDimensions = new SizeF(7F, 15F);
      AutoScaleMode = AutoScaleMode.Font;
      CancelButton = buttonCancel;
      ClientSize = new Size(312, 199);
      Controls.Add(buttonCancel);
      Controls.Add(buttonOk);
      Name = "Form1";
      Text = "Form1";
      ResumeLayout(false);
    }

    #endregion

    private Button buttonOk;
    private Button buttonCancel;
  }
}