# Chapter 1 - Introduction to Computers and the Internet

* HTML (HyperText Markup Language) : Specifies the **content** and **structure** of portable web pages.
* XHTML (eXtensible HTML)
* CSS (Cascading Style Sheets) : Specifies the **presentation** and **styling** of portable web pages independent of content and structure.
* JavaScript : Used to build **dynamic** web pages that respond to **events** and for client side programming. ECMAScipt5 - latest version. - ECMA (European Computer Manufacturers Association)
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
* Interpreted programs can run as soon as they're downloaded by the browser and do not have to wait for compilation but they generally run slower than compiled programs.

# Chapter 2 - Introduction to HTML5: Part 1

* HTML is a markup language.
* .html or .htm
* DOCTYPE : Document type declaration - Required in HTML5 documents. - Ensures that the browser renders the page in **standards** mode instead of **quirks** (to maintain backward compatibilty for old websites) mode.
* \<!--comments-->
* \<head> element contains information about the HTML5 document. Not displayed.
* UTF-8 (U from Universal Character Set + Transformation Format—8-bit) is a character encoding capable of encoding all possible characters (called code points) in Unicode. The encoding is variable-length and uses 8-bit code units. Displays many languages correctly.
* Void elements don't have end tags.
* Title enclosed by \<title> tag appears on the title bar of the browser. Used by search engines for indexing purposes.
* When a browser renders a paragraph it places extra space above and below the paragraph text. ( \<p>paratext\</p> )
* Use HTML5 validation services to check syntax of HTML5 documents. eg. validator.w3.org
* \<html lang = "en"> : Sets language of document as English. Useful for internationalization.
* Headings at the top of the page are indexed by search engines.
* Headings from \<h1> to \<h6>.
* Any displayed element can act as a hyperlink.
* \<strong> element is used to make text bold.
* \<em> element is used to italicize text.
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
* Character entity references : &code; - Used to represent special characters in HTML. eg. **<**  \&lt; **'**  \&apos; **>**  \&gt; **"**  \&quot; Check figure 2.8 page 49.
* Numeric character references: & can be represented by \&#38; (Decimal) and \&#x26; (Hex). These are the ASCII values of &.
* \<hr> : Inserts a horizontal line. - Avoid using this tag. Use CSS instead. Legacy code.
* \<del>...\</del> : Used to strike out content in between tags. Strike through text.
* \<sub>...\</sub> : Content in between tags is displayes as subscript.
* \<sup>...\</sup> : Content in between tags is displayed as superscript.
* In HTML5 &amp; is not required to represent &.
* \<ul>\<li>asdf\</li>\</ul> : Unordered list
* \<ol>\<li>asdf\</li>\</ol> : Ordered list
* \<table> element is used to create tables.
* \<table border = "1"> : Specifies that the browser should place borders around the table and the table's cells. Avoid using the border attribute. Use CSS's border property.
* \<table><caption>abc\</caption>... : Text inside caption tags is rendered above the table.
* \<table summary = "XTZ"> : Can be used by screen readers for disabled people. No visual effect. Obsolete in HTML5.
* \<thead> : Table head. - Uses \<th> tags for data.
* \<tfoot> : Table foot. - Uses \<th> tags for data.
* \<tbody> : Table body. - Content left aligned. Uses \<td> tags for data - left alignment. \<th> tags can also be used for bold and central alignment.
* \<tr> : Row of a table.
* By default table cells are only as wide as their largest element.
* \<th rowspan = "2"> : Merges two rows.
* \<th colspan = "5"> : Merges five columns.
* \<br> : Line break
* **Form** example
```html
<form method = "post" action = "http://www.deitel.com">
    <input type = "hidden" name = "recipient" value = "deitel@deitel.com">
    <input type = "hidden" name = "subject" value = "Feedback form">
    <input type = "hidden" name = "redirect" value = "main.html">
    <p><label>Name:
        <input name = "name" type = "text" size = "25" maxlength = "30">
    </label></p>
    <p>
        <input type = "submit" value = "Submit">
        <input type = "reset" value = "Reset">
    </p>
</form>
```
* "method" attribute can have the value "get" or "post".
* "action" attribute specifies the URL of the form handler script on the web server.
* "hidden" inputs allows us to send data that is not input by a user. Value in "name" attribute is used by the form handler to refer to the sent data. "value" is the data that is sent.
* "redirect" opens the page in "value" after the submit button has been clicked.
* "size" attribute specified the size of the text box.
* The value attribute of the reset and submit input element sets the text displayed on the button (the
default value is Reset and Submit if you omit the value attribute).
* Password box - Characters masked with asterisks. - Actual data sent to server.
```html
 <p>
    <label>
        Password:
        <input type = "password" name = "password" size = "25">
    </label>
</p>
```
* Text area
```html
<p><label>Comments: <br>
<textarea name = "comments"
rows = "4" cols = "36">Enter comments here.</textarea>
</label></p>
```
* Checkbox - Checkboxes that belong to a group are assigned the same name. - Make sure that have different values so that web server can distinguish them.
```html
<label>Site design
    <input name  = "thingsiliked" type = "checkbox" value = "Design">
</label>
<label>Links
    <input name = "thingsiliked" type = "checkbox" value = "Links">
</label>
```
* Radio button - Only 1 radio button can be selected at a time. - Radio buttons in a group have the same name attributes and are distinguished by their different values.
```html
<label>Search engine
    <input name = "how" type = "radio" value = "search engine" checked>
</label>
<label>Other
    <input name = "how" type = "radio" value = "other">
</label>
```
* Drop-down list
```html
<label>Rate our site:
    <select name = "rating">
        <option selected>Amazing</option>
        <option>Great</option>
        <option>Not bad</option>
        <option>Average</option>
        <option>Bad</option>
        <option>Awful</option>
    </select>
</label>
```
* For internal links:
\<h1 id = "abc">ABC\</h1>
\<a href = "#abc">Go to ABC\</a>
* Internal link to another file:
\<a href = "URL/filename.html#id">Go to abc\</a>
* "meta" elements are crawled by search engines. Information in them can be used for SEO (Search Engine Optimization). **name** identifies the type of meta element and **content** provides the information for search engines. Use only inside head section of HTML5 document.
eg.
```html
<meta name = "keywords" content = "web page, design,
HTML5, tutorial, personal, help, index, form,
contact, feedback, list, links, deitel">
<meta name = "description" content = "This website will
help you learn the basics of HTML5 and web page design
through the use of interactive examples and
instruction.">
```

# Chapter 3 - Introduction to HTML5: Part 2

* 
