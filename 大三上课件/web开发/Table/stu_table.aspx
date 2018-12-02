<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="stu_table.aspx.cs" Inherits="Table.stu_table" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title>学生表</title>
    <style type="text/css">
        #name,#ID,#sex,#age
        {
            /*background-color: #e1ddd9;*/
            text-align:center;
            font-style:normal;
            font-size:30px;
            border-radius:8px;
            font-family:Consolas;
            width:200px;
            height:30px;
            
        }
        #GridView1
        {
            font-size:28px;
            font-family:Consolas;
        }
        #Add_Button,#find,#delete
        {
             font-family:Consolas;
             font-size:18px;
             width:80px;
             height:30px;
             border-radius:8px;

        }
        #textname,#textage,#textsex,#textID{
            font-family:Consolas;
            font-size:20px;
        }

    </style>
</head>
<body>
    <form id="form1" runat="server">
        <asp:GridView ID="GridView1" runat="server" BackColor="White" BorderColor="#DEDFDE" BorderStyle="None" BorderWidth="1px" CellPadding="4" ForeColor="Black" GridLines="Vertical" style="z-index: 1; left: 53px; top: 46px; position: absolute; height: 202px; width: 812px" OnSelectedIndexChanged="GridView1_SelectedIndexChanged">
            <AlternatingRowStyle BackColor="White" />
            <FooterStyle BackColor="#CCCC99" />
            <HeaderStyle BackColor="#6B696B" Font-Bold="True" ForeColor="White" />
            <PagerStyle BackColor="#F7F7DE" ForeColor="Black" HorizontalAlign="Right" />
            <RowStyle BackColor="#F7F7DE" />
            <SelectedRowStyle BackColor="#CE5D5A" Font-Bold="True" ForeColor="White" />
            <SortedAscendingCellStyle BackColor="#FBFBF2" />
            <SortedAscendingHeaderStyle BackColor="#848384" />
            <SortedDescendingCellStyle BackColor="#EAEAD3" />
            <SortedDescendingHeaderStyle BackColor="#575357" />
        </asp:GridView>
        <asp:Label ID="textname" runat="server" style="z-index: 1; left: 892px; top: 80px; position: absolute" Text="姓名"></asp:Label>
       
        <asp:TextBox ID="age" runat="server" style="z-index: 1; left: 1010px; top: 215px; position: absolute"></asp:TextBox>
   
        <asp:Button ID="Add_Button" runat="server" style="z-index: 1; left: 1055px; top: 330px; position: absolute" Text="添加" OnClick="Add_Button_Click" />
      
       
        <asp:Label ID="textID" runat="server" style="z-index: 1; left: 892px; top: 147px; position: absolute" Text="ID"></asp:Label>
        <asp:Label ID="textage" runat="server" style="z-index: 1; left: 892px; top: 215px; position: absolute" Text="年龄"></asp:Label>
        <asp:Label ID="textsex" runat="server" style="z-index: 1; left: 892px; top: 278px; position: absolute" Text="性别"></asp:Label>
        <asp:Button ID="find" runat="server" style="z-index: 1; left: 947px; top: 329px; position: absolute; right: 383px" Text="查询" OnClick="find_Click" />
        <asp:Button ID="delete" runat="server" style="z-index: 1; left: 1163px; top: 331px; position: absolute" Text="删除" OnClick="delete_Click" />
       
        <asp:TextBox ID="sex" runat="server" style="z-index: 1; left: 1010px; top: 271px; position: absolute"></asp:TextBox> 
       
        <p>
            &nbsp;</p>
       
        <asp:TextBox ID="name" runat="server" style="z-index: 2; left: 1010px; top: 72px; position: absolute"></asp:TextBox>
        
        <p>
       
        <asp:TextBox ID="ID" runat="server" style="z-index: 1; left: 1010px; top: 147px; position: absolute; right: 154px;"></asp:TextBox>
        </p>
       
    </form>
</body>
</html>
