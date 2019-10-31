<%-- 
    Document   : checkbalance
    Created on : 31 Oct, 2019, 2:50:08 PM
    Author     : wad15
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Your balance</title>
    </head>
    <body>
        <%@ page import = "java.sql.*" %>
        <%
            String username = (String)session.getAttribute("username");
            if(username == null){
                response.sendRedirect("index.html");
            }
            
            Class.forName("org.postgresql.Driver");
            Connection con = DriverManager.getConnection("jdbc:postgresql://localhost:5432/bank1", "postgres", "root");
            Statement st = con.createStatement();
            ResultSet rs;
            rs = st.executeQuery("select balance from users where username='"+username+"';");
            if(rs.next()){
                out.println("Your balance is: &#8377;"+rs.getString("balance"));
            }
        %>
        <br>
        <a href="loggedin.jsp">Go back</a>
    </body>
</html>
