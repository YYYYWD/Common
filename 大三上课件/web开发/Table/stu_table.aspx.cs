using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.OleDb;
namespace Table
{
    public partial class stu_table : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            OleDbConnection conn = new OleDbConnection("provider=SQLOLEDB;Data Source=DESKTOP-6LD3FPP;Initial Catalog=Airport;Uid=test;Pwd=123456");
            conn.Open();
            string SQLstr_all = "select * from student order by age desc";
           
            OleDbDataAdapter myadapter = new OleDbDataAdapter(SQLstr_all,conn);
            DataSet myset = new DataSet();
            myadapter.Fill(myset);
            this.GridView1.DataSource = myset;
            this.GridView1.DataBind();//绑定到GridView1，相当于刷新
            conn.Close();

        }
        protected void Add(object sender,EventArgs e)
        {
            
        }

        protected void Add_Button_Click(object sender, EventArgs e)
        {
            OleDbConnection conn = new OleDbConnection("provider=SQLOLEDB;Data Source=DESKTOP-6LD3FPP;Initial Catalog=Airport;Uid=test;Pwd=123456");
            conn.Open();
            string SQLstr_all = "select * from student order by age desc";

            OleDbDataAdapter myadapter = new OleDbDataAdapter(SQLstr_all, conn);
            DataSet myset = new DataSet();
            myadapter.Fill(myset);
            //添加开始
            DataRow NowRow = myset.Tables[0].NewRow();
            //NowRow["name"];
            string name = Request["name"];
            string ID = Request["ID"];
            int age = int.Parse (Request["age"]);
            string  sex= Request["sex"];
            if (!name.Equals("") && !ID.Equals("") && !age.Equals("") && !sex.Equals(""))
            {
                conn.Close();
                return;
            }
            NowRow["name"] = name;
            NowRow["ID"] = ID;
            NowRow["age"] = age;
            NowRow["sex"] = sex;

            myset.Tables[0].Rows.Add(NowRow);
            OleDbCommandBuilder mybuild = new OleDbCommandBuilder(myadapter);
            myadapter.Update(myset);
            myset.Tables[0].AcceptChanges();

            DataView dv = new DataView();
            dv.Table = myset.Tables[0];
            dv.Sort = "age desc";
            this.GridView1.DataSource = dv;
            this.GridView1.DataBind();//绑定到GridView1，相当于刷新

            conn.Close();
        }

        protected void find_Click(object sender, EventArgs e)
        {
            OleDbConnection conn = new OleDbConnection("provider=SQLOLEDB;Data Source=DESKTOP-6LD3FPP;Initial Catalog=Airport;Uid=test;Pwd=123456");
            conn.Open();
            string name = Request["name"];
            string ID = Request["ID"];
            //int age = int.Parse(Request["age"]);
            //string sex = Request["sex"];
   
            string sql_string2 = "select * from student where ";

            if (!name.Equals(""))
            {
                sql_string2 =sql_string2+ "name= '" + name+"'";
            }
            if(!ID.Equals(""))
            {
                if (!name.Equals(""))
                    sql_string2 += "and";
                sql_string2 =sql_string2+ "ID='" + ID+"'";
            }
            if (name.Equals("") && ID.Equals(""))
                sql_string2 = "select * from student order by age desc";
            Console.Write(sql_string2);

            OleDbDataAdapter myadapter = new OleDbDataAdapter(sql_string2,conn);
            DataSet myset = new DataSet();
            myadapter.Fill(myset);
            this.GridView1.DataSource = myset;
            this.GridView1.DataBind();//绑定到GridView1，相当于刷新

            conn.Close();
        }

        protected void delete_Click(object sender, EventArgs e)
        {
            OleDbConnection conn = new OleDbConnection("provider=SQLOLEDB;Data Source=DESKTOP-6LD3FPP;Initial Catalog=Airport;Uid=test;Pwd=123456");
            conn.Open();
            string name = Request["name"];
            string ID = Request["ID"];
            string sql_delete = "delete from student where ";
            string sql_all = "select * from student order by age desc";
            if (!name.Equals(""))
            {
                sql_delete = sql_delete + "name= '" + name + "'";
            }
            if (!ID.Equals(""))
            {
                if (!name.Equals(""))
                    sql_delete += "and";
                sql_delete = sql_delete + "ID='" + ID + "'";
            }
            if (name.Equals("") && ID.Equals(""))
                sql_delete = "select * from student order by age desc";
            OleDbCommand cmd = new OleDbCommand();
            cmd.CommandText = sql_delete;
            cmd.Connection = conn;
            cmd.ExecuteNonQuery();

            OleDbDataAdapter myAdapter = new OleDbDataAdapter(sql_all, conn);
            DataSet myset = new DataSet();
            myAdapter.Fill(myset);
            this.GridView1.DataSource = myset;
            this.GridView1.DataBind();//绑定到GridView1，相当于刷新
            conn.Close();
        }

        protected void GridView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}