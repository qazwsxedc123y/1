// package main

// import (
// 	"context"
// 	"fmt"
// 	"log"
// 	"os"

// 	"github.com/sashabaranov/go-openai"
// )

// // 定义常量（你之前用的 ai.RoleSystem 等需要这些常量）
// const (
// 	RoleSystem    = "system"
// 	RoleUser      = "user"
// 	RoleAssistant = "assistant"
// )

// // 定义全局变量
// var MessageStore ChatMessages

// type ChatMessages []openai.ChatCompletionMessage

// func NewOpenAiClient() *openai.Client {
// 	token := os.Getenv("DashScope")
// 	// 修正：这是 API 地址，不是网页地址
// 	dashscope_url := "https://dashscope.aliyuncs.com/compatible-mode/v1"
// 	config := openai.DefaultConfig(token)
// 	config.BaseURL = dashscope_url

// 	return openai.NewClientWithConfig(config)
// }

// func Chat(message []openai.ChatCompletionMessage) openai.ChatCompletionMessage {
// 	c := NewOpenAiClient()
// 	rsp, err := c.CreateChatCompletion(context.TODO(), openai.ChatCompletionRequest{
// 		Model:    "qwen-plus",
// 		Messages: message,
// 	})
// 	if err != nil {
// 		log.Println(err)
// 		return openai.ChatCompletionMessage{}
// 	}

// 	return rsp.Choices[0].Message
// }

// func (cm *ChatMessages) AddFor(role string, msg string) {
// 	*cm = append(*cm, openai.ChatCompletionMessage{
// 		Role:    role,
// 		Content: msg,
// 	})
// }

// func (cm *ChatMessages) ToMessage() []openai.ChatCompletionMessage {
// 	ret := make([]openai.ChatCompletionMessage, len(*cm))
// 	for index, c := range *cm {
// 		ret[index] = c
// 	}
// 	return ret
// }

// func main() {
// 	MessageStore.AddFor(RoleSystem, "你是一个足球领域的专家，请尽可能地帮我回答与足球相关的问题。")
// 	MessageStore.AddFor(RoleUser, "C罗是哪个国家的足球运动员？")
// 	MessageStore.AddFor(RoleAssistant, "C罗是葡萄牙足球运动员。")
// 	MessageStore.AddFor(RoleUser, "内马尔呢？")

// 	response := Chat(MessageStore.ToMessage())
// 	fmt.Println(response.Content)
// }

// package main

// import (
// 	"fmt"

// 	"github.com/gogf/gf/v2"
// )

// func main() {
// 	fmt.Println("Hello GoFrame:", gf.VERSION)
// }

// package main

// import (
// 	"github.com/gogf/gf/v2/frame/g"
// 	"github.com/gogf/gf/v2/net/ghttp"
// )

// func main() {
// 	s := g.Server()
// 	s.BindHandler("/", func(r *ghttp.Request) {
// 		r.Response.Write("Hello World!")
// 	})
// 	s.SetPort(8000)
// 	s.Run()
// }

// package main

// import (
// 	"github.com/gogf/gf/v2/frame/g"
// 	"github.com/gogf/gf/v2/net/ghttp"
// )

// func main() {
// 	s := g.Server()
// 	s.BindHandler("/", func(r *ghttp.Request) {
// 		r.Response.Writef(
// 			"Hello %s! Your Age is %d",
// 			r.Get("name", "unknown").String(),
// 			r.Get("age").Int(),
// 		)
// 	})
// 	s.SetPort(8000)
// 	s.Run()
// }

// package main

// import (
// 	"github.com/gogf/gf/v2/frame/g"
// 	"github.com/gogf/gf/v2/net/ghttp"
// )

// type HelloReq struct {
// 	Name string // 名称
// 	Age  int    // 年龄
// }

// func main() {
// 	s := g.Server()
// 	s.BindHandler("/", func(r *ghttp.Request) {
// 		var req HelloReq
// 		if err := r.Parse(&req); err != nil {
// 			r.Response.Write(err.Error())
// 			return
// 		}
// 		if req.Name == "" {
// 			r.Response.Write("name should not be empty")
// 			return
// 		}
// 		if req.Age <= 0 {
// 			r.Response.Write("invalid age value")
// 			return
// 		}
// 		r.Response.Writef(
// 			"Hello %s! Your Age is %d",
// 			req.Name,
// 			req.Age,
// 		)
// 	})
// 	s.SetPort(8000)
// 	s.Run()
// }

// package main

// import (
// 	"context"

// 	"github.com/gogf/gf/v2/frame/g"
// 	"github.com/gogf/gf/v2/net/ghttp"
// )

// type HelloReq struct {
// 	g.Meta `path:"/" method:"get"`
// 	Name   string `v:"required" dc:"姓名"`
// 	Age    int    `v:"required" dc:"年龄"`
// }
// type HelloRes struct{}

// type Hello struct{}

// func (Hello) Say(ctx context.Context, req *HelloReq) (res *HelloRes, err error) {
// 	r := g.RequestFromCtx(ctx)
// 	r.Response.Writef(
// 		"Hello %s! Your Age is %d",
// 		req.Name,
// 		req.Age,
// 	)
// 	return
// }

// func main() {
// 	s := g.Server()
// 	s.Group("/", func(group *ghttp.RouterGroup) {
// 		group.Bind(
// 			new(Hello),
// 		)
// 	})
// 	s.SetPort(8000)
// 	s.Run()
// }

// package main

// import (
// 	"context"

// 	"github.com/gogf/gf/v2/frame/g"
// 	"github.com/gogf/gf/v2/net/ghttp"
// )

// type HelloReq struct {
// 	g.Meta `path:"/" method:"get"`
// 	Name   string `v:"required" dc:"姓名"`
// 	Age    int    `v:"required" dc:"年龄"`
// }
// type HelloRes struct{}

// type Hello struct{}

// func (Hello) Say(ctx context.Context, req *HelloReq) (res *HelloRes, err error) {
// 	r := g.RequestFromCtx(ctx)
// 	r.Response.Writef(
// 		"Hello %s! Your Age is %d",
// 		req.Name,
// 		req.Age,
// 	)
// 	return
// }

// func ErrorHandler(r *ghttp.Request) {
// 	// 执行路由函数
// 	r.Middleware.Next()
// 	// 判断是否产生错误
// 	if err := r.GetError(); err != nil {
// 		r.Response.Write("error occurs: ", err.Error())
// 		return
// 	}
// }

// func main() {
// 	s := g.Server()
// 	s.Group("/", func(group *ghttp.RouterGroup) {
// 		group.Middleware(ErrorHandler)
// 		group.Bind(
// 			new(Hello),
// 		)
// 	})
// 	s.SetPort(8000)
// 	s.Run()
// }

package main

import (
	"context"
	"fmt"

	"github.com/gogf/gf/v2/frame/g"
	"github.com/gogf/gf/v2/net/ghttp"
)

type Response struct {
	Message string      `json:"message" dc:"消息提示"`
	Data    interface{} `json:"data"    dc:"执行结果"`
}

type HelloReq struct {
	g.Meta `path:"/" method:"get"`
	Name   string `v:"required" json:"name" dc:"姓名"`
	Age    int    `v:"required" json:"age"  dc:"年龄"`
}
type HelloRes struct {
	Content string `json:"content" dc:"返回结果"`
}

type Hello struct{}

func (Hello) Say(ctx context.Context, req *HelloReq) (res *HelloRes, err error) {
	res = &HelloRes{
		Content: fmt.Sprintf(
			"Hello %s! Your Age is %d",
			req.Name,
			req.Age,
		),
	}
	return
}

func ResponseMiddleware(r *ghttp.Request) {
	r.Middleware.Next()

	var (
		msg string
		res = r.GetHandlerResponse()
		err = r.GetError()
	)
	if err != nil {
		msg = err.Error()
	} else {
		msg = "OK"
	}
	r.Response.WriteJson(Response{
		Message: msg,
		Data:    res,
	})
}

func main() {
	s := g.Server()
	s.Group("/", func(group *ghttp.RouterGroup) {
		group.Middleware(ResponseMiddleware)
		group.Bind(
			new(Hello),
		)
	})
	s.SetPort(8000)
	s.Run()
}
