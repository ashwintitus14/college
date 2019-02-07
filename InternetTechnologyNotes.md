# Chapter 1 - Introduction to Computers and the Internet

* HTML (HyperText Markup Language) : Specifies the **content** and **structure** of portable web pages.
* XHTML (eXtensible HTML)
* CSS (Cascading Style Sheets) : Specifies the **presentation** and **styling** of portable web pages independent of content and structure.
* JavaScript : Used to build **dynamic** web pages that respond to **events** and for client side programming. ECMAScipt5 - latest version.
* jQuery : JavaScript library with more GUI features
* Validators : Used to ensure that browsers process our code properly.
* mailto:emailAddress : Can be used as a hyperlink to open the default mail program with the "To" address filled.
* URI : Uniform Resource Identifier - Provides the name of a resource.
* URL : Uniform Resource Locator - URIs that start with http:// - Along with the name of the resource, provides location as well. Subset of URIs.
* Path names in URLs are usually virtual directories to hide resources' true location. Web server translates the virtual directory into a real location.
* MIME type: Multipurpose Internet Mail Extensions type - Specifies data formats which programs use to interpret data correctly. eg. Content-type: text/html, Content-type: text/plain, Content-type: image/jpeg - Included in HTTP header.
* HTTP **get** request: Used to retrieve information from a web server. eg. HTML document, images, search results. - Used to send data by appending it to the URL. eg.www.google.com/search?q=deitel Character limit may be there for URL.
* HTTP **post** request: Used to send data to a server as part of the HTTP message, not the URL. Cannot be seen by a typical user. Used to send large amounts of information.
* Multitier applications : Each tier may reside in separate computers.
    * **Top tier** : Client tier - User interface - Retrieves and displays data.
    * **Middle tier**: Business logic - Controller logic - Presentation logic
    * **Bottom tier**: Data/information tier - Data typically stored in RDBMSs.
* Sensitive information like passwords should not processed/validated on the client's side. Client can view source. All validation must be mirrored on the server side.
* W3C - World Wide Web Consortium - Founded by Tim Berner's Lee in October 1994.
* Recommendations : Web technologies standardized by W3C.
* Web 2.0 : Term coined by Dale Doughery of O'Reilly Media - Includes social networking sites, blogs, wikis. - Users create, update, modify, critique content.
* Semantic Web : Computers understanding the meaning of data on the web.
* Ajax : Allows web applications to perform like desktop applications.
* Data Heirarchy
    * Bits -> Characters -> Field -> Record -> File -> Database
* Interpreted programs can run as soon as they're downloaded by the broweser and do not have to wait for compilation but they generally run slower than compiled programs.

# Chapter 2 - Introduction to HTML5: Part 1

* HTML is a markup language.
* .html or .htm
* DOCTYPE : Document type declaration - Required in HTML5 documents. - Ensures that the browser renders the page in **standards** mode instead of **quirks** (to maintain backward compatibilty for old websites) mode.
* \<!--comments-->
* \<head> element contains information about the HTML5 document.
* Void elements don't have end tags.
* Title enclosed by \<title> tag appears on the title bar of the browser. Used by search engines for indexing purposes.
* When a browser renders a paragraph it places extra space above and below the paragraph text. ( \<p>paratext\</p> )
* Use HTML5 validation services to check syntax of HTML5 documents.
* \<html lang = "en"> : Sets language of document as English. Useful for internationalization.
* Headings at the top of the page are indexed by search engines.
* Headings from \<h1> to \<h6>.
* Any displayed element can act as a hyperlink.
* \<strong> element is used to make text bold.
* \<a href = "URL"> : a - anchor element, href - hypertext reference
* If web server cannot locate a document specified by a URL it returns Error 404.
* index.html is the default web page that is displayed if no filename is specified as part of the URL.
* \<a href = "mailto:EmailAddress"> : Attribute used to open mail client with To column filled.
* PNG : Portable Network Graphics
* JPEG : Joint Photographic Experts Group
* \<img src = "image_path" height = "213" width = "123" alt = "asdf">
    * Relative path is used for the image.
    * Always include height and width in the img tag so that browser can lay out the page properly and render the page faster.
    * alt attribute describe's the image's contents and is displayed if image is not found. Useful for speech synthesizers for visually impaired people.
* Void elements do not enclose any text in between opening and closing tags. eg. img element - Can be terminated with a /. eg. \<img src = "image_path" height = "213" width = "123" alt = "asdf" />
* To use images as hyperlinks enclose/nest img element inside anchor element. 
* 

