VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   6045
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   6690
   LinkTopic       =   "Form1"
   ScaleHeight     =   6045
   ScaleWidth      =   6690
   StartUpPosition =   3  '系統預設值
   Begin VB.CommandButton Command19 
      Caption         =   "0"
      Height          =   500
      Left            =   1200
      TabIndex        =   18
      Top             =   4680
      Width           =   800
   End
   Begin VB.CommandButton Command18 
      Caption         =   "9"
      Height          =   500
      Left            =   2200
      TabIndex        =   17
      Top             =   3960
      Width           =   800
   End
   Begin VB.CommandButton Command17 
      Caption         =   "8"
      Height          =   500
      Left            =   1200
      TabIndex        =   16
      Top             =   3960
      Width           =   800
   End
   Begin VB.CommandButton Command16 
      Caption         =   "7"
      Height          =   500
      Left            =   240
      TabIndex        =   15
      Top             =   3960
      Width           =   800
   End
   Begin VB.CommandButton Command15 
      Caption         =   "6"
      Height          =   500
      Left            =   2200
      TabIndex        =   14
      Top             =   3240
      Width           =   800
   End
   Begin VB.CommandButton Command14 
      Caption         =   "5"
      Height          =   500
      Left            =   1200
      TabIndex        =   13
      Top             =   3240
      Width           =   800
   End
   Begin VB.CommandButton Command13 
      Caption         =   "4"
      Height          =   500
      Left            =   240
      TabIndex        =   12
      Top             =   3240
      Width           =   800
   End
   Begin VB.CommandButton Command12 
      Caption         =   "3"
      Height          =   500
      Left            =   2200
      TabIndex        =   11
      Top             =   2520
      Width           =   800
   End
   Begin VB.CommandButton Command11 
      Caption         =   "2"
      Height          =   500
      Left            =   1200
      TabIndex        =   10
      Top             =   2520
      Width           =   800
   End
   Begin VB.CommandButton Command10 
      Caption         =   "1"
      Height          =   500
      Left            =   240
      TabIndex        =   9
      Top             =   2520
      Width           =   800
   End
   Begin VB.CommandButton Command9 
      Caption         =   "靜音"
      Height          =   500
      Left            =   240
      TabIndex        =   8
      Top             =   1800
      Width           =   800
   End
   Begin MSCommLib.MSComm MSComm1 
      Left            =   3360
      Top             =   2040
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      DTREnable       =   -1  'True
   End
   Begin VB.CommandButton Command8 
      Height          =   500
      Left            =   3200
      TabIndex        =   7
      Top             =   1080
      Width           =   800
   End
   Begin VB.CommandButton Command7 
      Caption         =   "返回"
      Height          =   500
      Left            =   2200
      TabIndex        =   6
      Top             =   1080
      Width           =   800
   End
   Begin VB.CommandButton Command6 
      Caption         =   "頻道-"
      Height          =   500
      Left            =   1200
      TabIndex        =   5
      Top             =   1080
      Width           =   800
   End
   Begin VB.CommandButton Command5 
      Caption         =   "音量-"
      Height          =   500
      Left            =   240
      TabIndex        =   4
      Top             =   1080
      Width           =   800
   End
   Begin VB.CommandButton Command4 
      Caption         =   "選擇"
      Height          =   500
      Left            =   3200
      TabIndex        =   3
      Top             =   360
      Width           =   800
   End
   Begin VB.CommandButton Command3 
      Caption         =   "資訊"
      Height          =   500
      Left            =   2200
      TabIndex        =   2
      Top             =   360
      Width           =   800
   End
   Begin VB.CommandButton Command2 
      Caption         =   "頻道+"
      Height          =   500
      Left            =   1200
      TabIndex        =   1
      Top             =   360
      Width           =   800
   End
   Begin VB.CommandButton Command1 
      Caption         =   "音量+"
      Height          =   500
      Left            =   240
      TabIndex        =   0
      Top             =   360
      Width           =   800
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
Dim arrData(1 To 5) As Byte

arrData(1) = &HA1
arrData(2) = &HF1
arrData(3) = &HBE
arrData(4) = &HBE
arrData(5) = &H36
MSComm1.Output = arrData()

End Sub

Private Sub Command10_Click()
Dim arrData(1 To 5) As Byte

arrData(1) = &HA1
arrData(2) = &HF1
arrData(3) = &HBE
arrData(4) = &HBE
arrData(5) = &H21
MSComm1.Output = arrData()

End Sub

Private Sub Command11_Click()
Dim arrData(1 To 5) As Byte

arrData(1) = &HA1
arrData(2) = &HF1
arrData(3) = &HBE
arrData(4) = &HBE
arrData(5) = &H22
MSComm1.Output = arrData()

End Sub

Private Sub Command12_Click()
Dim arrData(1 To 5) As Byte

arrData(1) = &HA1
arrData(2) = &HF1
arrData(3) = &HBE
arrData(4) = &HBE
arrData(5) = &H23
MSComm1.Output = arrData()

End Sub

Private Sub Command13_Click()
Dim arrData(1 To 5) As Byte

arrData(1) = &HA1
arrData(2) = &HF1
arrData(3) = &HBE
arrData(4) = &HBE
arrData(5) = &H24
MSComm1.Output = arrData()

End Sub

Private Sub Command14_Click()
Dim arrData(1 To 5) As Byte

arrData(1) = &HA1
arrData(2) = &HF1
arrData(3) = &HBE
arrData(4) = &HBE
arrData(5) = &H25
MSComm1.Output = arrData()

End Sub

Private Sub Command15_Click()
Dim arrData(1 To 5) As Byte

arrData(1) = &HA1
arrData(2) = &HF1
arrData(3) = &HBE
arrData(4) = &HBE
arrData(5) = &H26
MSComm1.Output = arrData()

End Sub

Private Sub Command16_Click()
Dim arrData(1 To 5) As Byte

arrData(1) = &HA1
arrData(2) = &HF1
arrData(3) = &HBE
arrData(4) = &HBE
arrData(5) = &H27
MSComm1.Output = arrData()

End Sub

Private Sub Command17_Click()
Dim arrData(1 To 5) As Byte

arrData(1) = &HA1
arrData(2) = &HF1
arrData(3) = &HBE
arrData(4) = &HBE
arrData(5) = &H28
MSComm1.Output = arrData()

End Sub

Private Sub Command18_Click()
Dim arrData(1 To 5) As Byte

arrData(1) = &HA1
arrData(2) = &HF1
arrData(3) = &HBE
arrData(4) = &HBE
arrData(5) = &H29
MSComm1.Output = arrData()

End Sub

Private Sub Command19_Click()
Dim arrData(1 To 5) As Byte

arrData(1) = &HA1
arrData(2) = &HF1
arrData(3) = &HBE
arrData(4) = &HBE
arrData(5) = &H20
MSComm1.Output = arrData()

End Sub

Private Sub Command2_Click()
Dim arrData(1 To 5) As Byte

arrData(1) = &HA1
arrData(2) = &HF1
arrData(3) = &HBE
arrData(4) = &HBE
arrData(5) = &H7B
MSComm1.Output = arrData()

End Sub


Private Sub Command3_Click()
Dim arrData(1 To 5) As Byte

arrData(1) = &HA1
arrData(2) = &HF1
arrData(3) = &HBE
arrData(4) = &HBE
arrData(5) = &H74
MSComm1.Output = arrData()

End Sub

Private Sub Command4_Click()
Dim arrData(1 To 5) As Byte

arrData(1) = &HA1
arrData(2) = &HF1
arrData(3) = &HBE
arrData(4) = &HBE
arrData(5) = &H7F
MSComm1.Output = arrData()

End Sub

Private Sub Command5_Click()
Dim arrData(1 To 5) As Byte

arrData(1) = &HA1
arrData(2) = &HF1
arrData(3) = &HBE
arrData(4) = &HBE
arrData(5) = &H37
MSComm1.Output = arrData()

End Sub

Private Sub Command6_Click()
Dim arrData(1 To 5) As Byte

arrData(1) = &HA1
arrData(2) = &HF1
arrData(3) = &HBE
arrData(4) = &HBE
arrData(5) = &H7C
MSComm1.Output = arrData()

End Sub

Private Sub Command7_Click()
Dim arrData(1 To 5) As Byte

arrData(1) = &HA1
arrData(2) = &HF1
arrData(3) = &HBE
arrData(4) = &HBE
arrData(5) = &H78
MSComm1.Output = arrData()

End Sub

Private Sub Command8_Click()
MSComm1.Output = "W100101065"
MSComm1.Output = Chr(13)
MSComm1.Output = Chr(10)
End Sub

Private Sub Command9_Click()
Dim arrData(1 To 5) As Byte

arrData(1) = &HA1
arrData(2) = &HF1
arrData(3) = &HBE
arrData(4) = &HBE
arrData(5) = &H63
MSComm1.Output = arrData()

End Sub

Private Sub Form_Load()
MSComm1.PortOpen = True
End Sub
