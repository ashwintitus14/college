<%-- 
    Document   : register
    Created on : 31 Oct, 2019, 3:15:05 PM
    Author     : wad15
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>New registration</title>
    </head>
    <body>
        <%@ page import = "java.sql.*" %>
        <%
            String username = request.getParameter("username");
            String password = request.getParameter("password");
            
            Class.forName("org.postgresql.Driver");
            Connection con = DriverManager.getConnection("jdbc:postgresql://localhost:5432/bank1", "postgres", "root");
            Statement st = con.createStatement();
            int i = st.executeUpdate("insert into users values('"+username+"','"+password+"');");
        %>
        <br>
        <p>New user registered successfully!</p>
        <br>
        <a href="index.html">Login</a>
    </body>
</html>
