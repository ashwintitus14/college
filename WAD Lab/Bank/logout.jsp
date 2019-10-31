<%-- 
    Document   : logout
    Created on : 31 Oct, 2019, 2:37:46 PM
    Author     : wad15
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Logout</title>
    </head>
    <body>
        <% 
            session.invalidate();
            response.sendRedirect("index.html");
        %>
        
    </body>
</html>
