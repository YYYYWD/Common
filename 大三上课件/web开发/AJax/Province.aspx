<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Province.aspx.cs" Inherits="AJax.Province" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>省市联动</title>
    <style type="text/css">
        #Province1{
            position:absolute;
            left:250px;
            top:50px;
            font-family:Consolas;
            font-size:18px;
            width:155px;
            height:50px;
            border-radius:8px;
        }
        #City1
        {
            position:absolute;
            left:450px;
            top:50px;
            font-family:Consolas;
            font-size:18px;
            width:155px;
            height:50px;
            border-radius:8px;
        }
        
    </style>
</head>
<body>
    <form id="form1" runat="server">
        <div>

        </div>
       
        <asp:ScriptManager ID="ScriptManager1" runat="server">
        </asp:ScriptManager>
         <asp:UpdatePanel ID="UpdatePanel1" runat="server">
             <ContentTemplate>
                 <asp:DropDownList ID="Province1" runat="server" OnSelectedIndexChanged="Province1_SelectedIndexChanged" AutoPostBack="true"></asp:DropDownList>
                 <asp:DropDownList ID="City1" runat="server" OnSelectedIndexChanged="City_SelectedIndexChanged" AutoPostBack="true"></asp:DropDownList>
             </ContentTemplate>
        </asp:UpdatePanel>
               
    </form>
</body>
</html>
