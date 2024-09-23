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
      mLabel = new Label();
      mTextBox = new TextBox();
      mButtonReverse = new Button();
      SuspendLayout();
      // 
      // buttonOk
      // 
      buttonOk.Anchor = AnchorStyles.Bottom | AnchorStyles.Right;
      buttonOk.DialogResult = DialogResult.OK;
      buttonOk.Location = new Point(113, 79);
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
      buttonCancel.Location = new Point(208, 79);
      buttonCancel.Name = "buttonCancel";
      buttonCancel.Size = new Size(75, 23);
      buttonCancel.TabIndex = 1;
      buttonCancel.Text = "Cancel";
      buttonCancel.UseVisualStyleBackColor = true;
      // 
      // mLabel
      // 
      mLabel.AutoSize = true;
      mLabel.Location = new Point(16, 22);
      mLabel.Name = "mLabel";
      mLabel.Size = new Size(31, 15);
      mLabel.TabIndex = 2;
      mLabel.Text = "Text:";
      // 
      // mTextBox
      // 
      mTextBox.Anchor = AnchorStyles.Top | AnchorStyles.Left | AnchorStyles.Right;
      mTextBox.Location = new Point(53, 19);
      mTextBox.Name = "mTextBox";
      mTextBox.Size = new Size(150, 23);
      mTextBox.TabIndex = 3;
      // 
      // mButtonReverse
      // 
      mButtonReverse.Anchor = AnchorStyles.Top | AnchorStyles.Right;
      mButtonReverse.Location = new Point(209, 19);
      mButtonReverse.Name = "mButtonReverse";
      mButtonReverse.Size = new Size(75, 23);
      mButtonReverse.TabIndex = 4;
      mButtonReverse.Text = "Reverse";
      mButtonReverse.UseVisualStyleBackColor = true;
      mButtonReverse.Click += mButtonReverse_Click;
      // 
      // Form1
      // 
      AcceptButton = buttonOk;
      AutoScaleDimensions = new SizeF(7F, 15F);
      AutoScaleMode = AutoScaleMode.Font;
      CancelButton = buttonCancel;
      ClientSize = new Size(295, 115);
      Controls.Add(mButtonReverse);
      Controls.Add(mTextBox);
      Controls.Add(mLabel);
      Controls.Add(buttonCancel);
      Controls.Add(buttonOk);
      Name = "Form1";
      Text = "Form1";
      ResumeLayout(false);
      PerformLayout();
    }

    #endregion

    private Button buttonOk;
    private Button buttonCancel;
    private Label mLabel;
    private TextBox mTextBox;
    private Button mButtonReverse;
  }
}