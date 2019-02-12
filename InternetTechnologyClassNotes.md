# 12/2/19
## CSS3 (Cascading Style Sheets)
* Makes presentation/style of the page independent of the content and structure.
* CSS rule set : Selector-Declaration block
* eg. 
```css
      h1 {
          color:blue; 
          font-size:12px;
          }
```
* Tag {Property:Value;}
* \<em> : To display the text in italics.
* Ways to insert CSS:
  * Inline styles - Inside the tag
  * Embedded style sheets - Inside the same page but outside the tag
  * External style sheets
* Inline style
```html
<p style="color:red; font-size:12px>Hello</p>
```

* When multiple font families are specified each one is used from left to right based on availability.
* If same attributes are used multipe times, the latest one overrides the rest.
* Embedded style sheets - Apply for all instances of a tag everywhere.
```html
<style type = "text/css">
			body {
					background-color: powderblue;
			}
			em {
					font-weight: bold;
					color: black;
			}
			p {
					color: red; 
					font-family: comic-sans;
			}
			.special {
						color: purple;
						color: green
			}
		</style>
```

