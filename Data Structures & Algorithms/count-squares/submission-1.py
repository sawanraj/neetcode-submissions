class CountSquares:

    def __init__(self):
        self.point_counts=defaultdict(int)
        self.points=[]
        

    def add(self, point: List[int]) -> None:
        self.point_counts[tuple(point)]+=1
        self.points.append(point)

    def count(self, point: List[int]) -> int:
        qx,qy =point
        total_squares=0

        for x,y in self.points:
            if abs(qx-x)!=abs(qy-y) or qx==x or qy==y:
                continue
            total_squares+=self.point_counts[(qx,y)]*self.point_counts[(x,qy)]
        return total_squares
                                                     


