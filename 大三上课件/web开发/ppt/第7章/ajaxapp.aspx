<%@ Page Language="C#" AutoEventWireup="true" CodeFile="ajaxapp.aspx.cs" Inherits="ajaxapp" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
    </div>
    <asp:ScriptManager ID="ScriptManager1" runat="server">
    </asp:ScriptManager>
    <asp:UpdatePanel ID="UpdatePanel1" runat="server">
        <ContentTemplate>
            <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            <asp:Button ID="Button1" runat="server" Text="Button" onclick="Button1_Click" />
            <br />
            <br />
            <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
            <br />
        </ContentTemplate>
    </asp:UpdatePanel>
    <p>
        <img alt="" src="jpg/卢淑芳答辩_010.jpg" style="width: 348px; height: 236px" /></p>
    <p>
        &nbsp;</p>
    </form>
    </body>
</html>
