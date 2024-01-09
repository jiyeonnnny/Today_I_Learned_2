# IllegalArgumentException

## Error 내용
```
java.lang.IllegalArgumentException: 
Name for argument of type [java.lang.Long] 
not specified, and parameter name information not available via reflection. 
Ensure that the compiler uses the '-parameters' flag.
```

<br>
<br>
<br>

## Error 원인 및 해결
```java
@GetMapping("items/{itemId}/edit")
public String updateItemForm(@PathVariable("itemId") Long itemId, Model model){
    Book item = (Book) itemService.findOne(itemId);
    BookForm form = new BookForm();
    form.setId(item.getId());
    form.setName(item.getName());
    form.setPrice(item.getPrice());
    form.setStockQuantity(item.getStockQuantity());
    form.setAuthor(item.getAuthor());
    form.setIsbn(item.getIsbn());
    model.addAttribute("form", form);
    return "items/updateItemForm";
}


@PostMapping("items/{itemId}/edit")
public String updateItem(@PathVariable Long itemId, @ModelAttribute("form") BookForm form){
    itemService.updateItem(itemId, form.getName(), form.getPrice(), form.getStockQuantity());
    return "redirect:/items";
}
```
```java
@PostMapping("items/{itemId}/edit")
public String updateItem(@PathVariable("itemId") Long itemId, @ModelAttribute("form") BookForm form){
    itemService.updateItem(itemId, form.getName(), form.getPrice(), form.getStockQuantity());
    return "redirect:/items";
}
```
- updateItem 함수의 PathVariable 위치
- 클래스 파일의 파라미터 이름 정보가 없다는 뜻
- @Pathvariable을 정의하면서, name 또는 value 속성을 명시하지 않아서 발생한 Error

<br>
<br>
<br>
