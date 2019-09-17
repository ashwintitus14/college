/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import java.sql.*;

/**
 *
 * @author wad15
 */
@WebServlet(urlPatterns = {"/displayall"})
public class displayall extends HttpServlet {
    
    Connection connection;
    String url = "jdbc:postgresql://localhost:5432/student";
    String dbusername = "postgres";
    String dbpassword = "root";
    
    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet create</title>");            
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Servlet create at " + request.getContextPath() + "</h1>");
            out.println("</body>");
            out.println("</html>");
        }
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        //processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        //processRequest(request, response);
        PrintWriter out = response.getWriter();
        
        try {
            Class.forName("org.postgresql.Driver");
        } catch(ClassNotFoundException e) {
            out.println(e.getMessage());
        }
        
        try {
            String name, dob, dept, empno;
                        
            connection = DriverManager.getConnection(url, dbusername, dbpassword);
            Statement stmt = connection.createStatement();
            ResultSet rs = stmt.executeQuery("select * from emp;");
            
            out.println("<!DOCTYPE html>");
            out.println("<html><body><table border='1'><tr><th>Name</th><th>DOB</th><th>Department</th><th>Employee No.</th></tr>");
            while(rs.next()) {
                name = rs.getString("name");
                dob = rs.getString("dob");
                dept = rs.getString("dept");
                empno = rs.getString("empno");
                
                out.println("<tr><td>"+name+"</td><td>"+dob+"</td><td>"+dept+"</td><td>"+empno+"</td></tr>");
                
                
            }
            out.println("</tr></table>");
            connection.close();
            
            out.println("<a href='index.html'>Go back to main menu</a>");
            out.println("</body></html>");
        
        } catch(SQLException ex) {
            out.println(ex.getMessage());
        }
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
